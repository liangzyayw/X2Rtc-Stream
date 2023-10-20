/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MODULES_RTP_RTCP_INCLUDE_RTP_RTCP_DEFINES_H_
#define MODULES_RTP_RTCP_INCLUDE_RTP_RTCP_DEFINES_H_

#include "api/transport/network_types.h"

#include "RTC/RTCP/FeedbackRtpTransport.hpp"

#include <absl/types/optional.h>
#include <stddef.h>
#include <list>
#include "absl/memory/memory.h"
#include <vector>

#include "absl/strings/string_view.h"
#include "absl/types/optional.h"
#include "absl/types/variant.h"
//#include "api/array_view.h"
//#include "api/audio_codecs/audio_format.h"
//#include "api/rtp_headers.h"
#include "api/transport/network_types.h"

#define RTCP_CNAME_SIZE 256  // RFC 3550 page 44, including null termination
#define IP_PACKET_SIZE 1500  // we assume ethernet

namespace webrtc {
class RtpPacket;
namespace rtcp {
class TransportFeedback;
}

const int kVideoPayloadTypeFrequency = 90000;

// TODO(bugs.webrtc.org/6458): Remove this when all the depending projects are
// updated to correctly set rtp rate for RtcpSender.
const int kBogusRtpRateForAudioRtcp = 8000;

// Minimum RTP header size in bytes.
const uint8_t kRtpHeaderSize = 12;

bool IsLegalMidName(absl::string_view name);
bool IsLegalRsidName(absl::string_view name);

// This enum must not have any gaps, i.e., all integers between
// kRtpExtensionNone and kRtpExtensionNumberOfExtensions must be valid enum
// entries.
enum RTPExtensionType : int {
  kRtpExtensionNone,
  kRtpExtensionTransmissionTimeOffset,
  kRtpExtensionAudioLevel,
  kRtpExtensionInbandComfortNoise,
  kRtpExtensionAbsoluteSendTime,
  kRtpExtensionAbsoluteCaptureTime,
  kRtpExtensionVideoRotation,
  kRtpExtensionTransportSequenceNumber,
  kRtpExtensionTransportSequenceNumber02,
  kRtpExtensionPlayoutDelay,
  kRtpExtensionVideoContentType,
  kRtpExtensionVideoTiming,
  kRtpExtensionFrameMarking,
  kRtpExtensionRtpStreamId,
  kRtpExtensionRepairedRtpStreamId,
  kRtpExtensionMid,
  kRtpExtensionGenericFrameDescriptor00,
  kRtpExtensionGenericFrameDescriptor = kRtpExtensionGenericFrameDescriptor00,
  kRtpExtensionGenericFrameDescriptor01,
  kRtpExtensionGenericFrameDescriptor02,
  kRtpExtensionColorSpace,
  kRtpExtensionNumberOfExtensions  // Must be the last entity in the enum.
};

enum RTCPAppSubTypes { kAppSubtypeBwe = 0x00 };

// TODO(sprang): Make this an enum class once rtcp_receiver has been cleaned up.
enum RTCPPacketType : uint32_t {
  kRtcpReport = 0x0001,
  kRtcpSr = 0x0002,
  kRtcpRr = 0x0004,
  kRtcpSdes = 0x0008,
  kRtcpBye = 0x0010,
  kRtcpPli = 0x0020,
  kRtcpNack = 0x0040,
  kRtcpFir = 0x0080,
  kRtcpTmmbr = 0x0100,
  kRtcpTmmbn = 0x0200,
  kRtcpSrReq = 0x0400,
  kRtcpApp = 0x1000,
  kRtcpLossNotification = 0x2000,
  kRtcpRemb = 0x10000,
  kRtcpTransmissionTimeOffset = 0x20000,
  kRtcpXrReceiverReferenceTime = 0x40000,
  kRtcpXrDlrrReportBlock = 0x80000,
  kRtcpTransportFeedback = 0x100000,
  kRtcpXrTargetBitrate = 0x200000
};

enum RtxMode {
  kRtxOff = 0x0,
  kRtxRetransmitted = 0x1,     // Only send retransmissions over RTX.
  kRtxRedundantPayloads = 0x2  // Preventively send redundant payloads
                               // instead of padding.
};

const size_t kRtxHeaderSize = 2;

struct RTCPReportBlock {
  RTCPReportBlock()
      : sender_ssrc(0),
        source_ssrc(0),
        fraction_lost(0),
        packets_lost(0),
        extended_highest_sequence_number(0),
        jitter(0),
        last_sender_report_timestamp(0),
        delay_since_last_sender_report(0) {}

  RTCPReportBlock(uint32_t sender_ssrc,
                  uint32_t source_ssrc,
                  uint8_t fraction_lost,
                  int32_t packets_lost,
                  uint32_t extended_highest_sequence_number,
                  uint32_t jitter,
                  uint32_t last_sender_report_timestamp,
                  uint32_t delay_since_last_sender_report)
      : sender_ssrc(sender_ssrc),
        source_ssrc(source_ssrc),
        fraction_lost(fraction_lost),
        packets_lost(packets_lost),
        extended_highest_sequence_number(extended_highest_sequence_number),
        jitter(jitter),
        last_sender_report_timestamp(last_sender_report_timestamp),
        delay_since_last_sender_report(delay_since_last_sender_report) {}

  // Fields as described by RFC 3550 6.4.2.
  uint32_t sender_ssrc;  // SSRC of sender of this report.
  uint32_t source_ssrc;  // SSRC of the RTP packet sender.
  uint8_t fraction_lost;
  int32_t packets_lost;  // 24 bits valid.
  uint32_t extended_highest_sequence_number;
  uint32_t jitter;
  uint32_t last_sender_report_timestamp;
  uint32_t delay_since_last_sender_report;
};

typedef std::list<RTCPReportBlock> ReportBlockList;

class RtcpBandwidthObserver {
 public:
  // REMB or TMMBR
  virtual void OnReceivedEstimatedBitrate(uint32_t bitrate) = 0;

  virtual void OnReceivedRtcpReceiverReport(
      const ReportBlockList& report_blocks,
      int64_t rtt,
      int64_t now_ms) = 0;

  virtual ~RtcpBandwidthObserver() {}
};

struct PacketFeedback {
  PacketFeedback(int64_t arrival_time_ms, uint16_t sequence_number);

  PacketFeedback(int64_t arrival_time_ms,
                 int64_t send_time_ms,
                 uint16_t sequence_number,
                 size_t payload_size,
                 const PacedPacketInfo& pacing_info);

  PacketFeedback(int64_t creation_time_ms,
                 uint16_t sequence_number,
                 size_t payload_size,
                 uint16_t local_net_id,
                 uint16_t remote_net_id,
                 const PacedPacketInfo& pacing_info);

  PacketFeedback(int64_t creation_time_ms,
                 int64_t arrival_time_ms,
                 int64_t send_time_ms,
                 uint16_t sequence_number,
                 size_t payload_size,
                 uint16_t local_net_id,
                 uint16_t remote_net_id,
                 const PacedPacketInfo& pacing_info);
  PacketFeedback(const PacketFeedback&);
  PacketFeedback& operator=(const PacketFeedback&);
  ~PacketFeedback();

  static constexpr int kNotAProbe = -1;
  static constexpr int64_t kNotReceived = -1;
  static constexpr int64_t kNoSendTime = -1;

  // NOTE! The variable |creation_time_ms| is not used when testing equality.
  //       This is due to |creation_time_ms| only being used by SendTimeHistory
  //       for book-keeping, and is of no interest outside that class.
  // TODO(philipel): Remove |creation_time_ms| from PacketFeedback when cleaning
  //                 up SendTimeHistory.
  bool operator==(const PacketFeedback& rhs) const;

  // Time corresponding to when this object was created.
  int64_t creation_time_ms;
  // Time corresponding to when the packet was received. Timestamped with the
  // receiver's clock. For unreceived packet, the sentinel value kNotReceived
  // is used.
  int64_t arrival_time_ms;
  // Time corresponding to when the packet was sent, timestamped with the
  // sender's clock.
  int64_t send_time_ms;
  // Packet identifier, incremented with 1 for every packet generated by the
  // sender.
  uint16_t sequence_number;
  // Session unique packet identifier, incremented with 1 for every packet
  // generated by the sender.
  int64_t long_sequence_number;
  // Size of the packet excluding RTP headers.
  size_t payload_size;
  // Size of preceeding packets that are not part of feedback.
  size_t unacknowledged_data;
  // The network route ids that this packet is associated with.
  uint16_t local_net_id;
  uint16_t remote_net_id;
  // Pacing information about this packet.
  PacedPacketInfo pacing_info;

  // The SSRC and RTP sequence number of the packet this feedback refers to.
  absl::optional<uint32_t> ssrc;
  uint16_t rtp_sequence_number;
};

struct RtpPacketSendInfo {
 public:
  RtpPacketSendInfo() = default;

  uint16_t transport_sequence_number = 0;
  uint32_t ssrc = 0;
  uint16_t rtp_sequence_number = 0;
  // Get rid of this flag when all code paths populate |rtp_sequence_number|.
  bool has_rtp_sequence_number = false;
  size_t length = 0;
  PacedPacketInfo pacing_info;
};

class NetworkStateEstimateObserver {
 public:
  virtual void OnRemoteNetworkEstimate(NetworkStateEstimate estimate) = 0;
  virtual ~NetworkStateEstimateObserver() = default;
};

class TransportFeedbackObserver {
 public:
  TransportFeedbackObserver() {}
  virtual ~TransportFeedbackObserver() {}

  virtual void OnAddPacket(const RtpPacketSendInfo& packet_info) = 0;
  virtual void OnTransportFeedback(const RTC::RTCP::FeedbackRtpTransportPacket& feedback) = 0;
};

class PacketFeedbackObserver {
 public:
  virtual ~PacketFeedbackObserver() = default;

  virtual void OnPacketAdded(uint32_t ssrc, uint16_t seq_num) = 0;
  virtual void OnPacketFeedbackVector(
      const std::vector<PacketFeedback>& packet_feedback_vector) = 0;
};

// Callback, used to notify an observer whenever the send-side delay is updated.
class SendSideDelayObserver {
 public:
  virtual ~SendSideDelayObserver() {}
  virtual void SendSideDelayUpdated(int avg_delay_ms,
                                    int max_delay_ms,
                                    uint64_t total_delay_ms,
                                    uint32_t ssrc) = 0;
};

// Callback, used to notify an observer whenever a packet is sent to the
// transport.
// TODO(asapersson): This class will remove the need for SendSideDelayObserver.
// Remove SendSideDelayObserver once possible.
class SendPacketObserver {
 public:
  virtual ~SendPacketObserver() {}
  virtual void OnSendPacket(uint16_t packet_id,
                            int64_t capture_time_ms,
                            uint32_t ssrc) = 0;
};

// Status returned from TimeToSendPacket() family of callbacks.
enum class RtpPacketSendResult {
  kSuccess,               // Packet sent OK.
  kTransportUnavailable,  // Network unavailable, try again later.
  kPacketNotFound  // SSRC/sequence number does not map to an available packet.
};

}  // namespace webrtc
#endif  // MODULES_RTP_RTCP_INCLUDE_RTP_RTCP_DEFINES_H_
