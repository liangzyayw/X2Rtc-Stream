/*
*  Copyright (c) 2022 The X2RTC project authors. All Rights Reserved.
*
*  Please visit https://www.x2rtc.com for detail.
*
*  Author: Eric(eric@x2rtc.com)
*  Twitter: @X2rtc_cloud
*
* The GNU General Public License is a free, copyleft license for
* software and other kinds of works.
*
* The licenses for most software and other practical works are designed
* to take away your freedom to share and change the works.  By contrast,
* the GNU General Public License is intended to guarantee your freedom to
* share and change all versions of a program--to make sure it remains free
* software for all its users.  We, the Free Software Foundation, use the
* GNU General Public License for most of our software; it applies also to
* any other work released this way by its authors.  You can apply it to
* your programs, too.
* See the GNU LICENSE file for more info.
*/
#ifndef __X2_AUD_A_UTIL_H__
#define __X2_AUD_A_UTIL_H__
#include "X2RtcDef.h"

X2R_API int X2R_CALL X2MixAudio(int iChannelNum, short* sourceData1, short* sourceData2, float fBackgroundGain, float fWordsGain, short *outputData);

X2R_API int X2R_CALL X2VolAudio(int iChannelNum, short* sourceData1, float fBackgroundGain);


#endif	// __X2_AUD_A_UTIL_H__
