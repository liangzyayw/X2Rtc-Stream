# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_threadPoolBenchmark.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_threadPoolBenchmark.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_threadPoolBenchmark.dir/flags.make

tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o: tests/CMakeFiles/test_threadPoolBenchmark.dir/flags.make
tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o: ../tests/test_threadPoolBenchmark.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o"
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o -c /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/tests/test_threadPoolBenchmark.cpp

tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.i"
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/tests/test_threadPoolBenchmark.cpp > CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.i

tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.s"
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/tests/test_threadPoolBenchmark.cpp -o CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.s

# Object files for target test_threadPoolBenchmark
test_threadPoolBenchmark_OBJECTS = \
"CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o"

# External object files for target test_threadPoolBenchmark
test_threadPoolBenchmark_EXTERNAL_OBJECTS =

bin/test_threadPoolBenchmark: tests/CMakeFiles/test_threadPoolBenchmark.dir/test_threadPoolBenchmark.cpp.o
bin/test_threadPoolBenchmark: tests/CMakeFiles/test_threadPoolBenchmark.dir/build.make
bin/test_threadPoolBenchmark: lib/libZLToolKit.so
bin/test_threadPoolBenchmark: tests/CMakeFiles/test_threadPoolBenchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_threadPoolBenchmark"
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_threadPoolBenchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_threadPoolBenchmark.dir/build: bin/test_threadPoolBenchmark

.PHONY : tests/CMakeFiles/test_threadPoolBenchmark.dir/build

tests/CMakeFiles/test_threadPoolBenchmark.dir/clean:
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_threadPoolBenchmark.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_threadPoolBenchmark.dir/clean

tests/CMakeFiles/test_threadPoolBenchmark.dir/depend:
	cd /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/tests /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests /mnt/work/XRtc-Project/ZLXxxxKit/ZLToolKit/linux_build/tests/CMakeFiles/test_threadPoolBenchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_threadPoolBenchmark.dir/depend

