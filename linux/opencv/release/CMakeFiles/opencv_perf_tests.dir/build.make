# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bravej/Documents/AnalyseImage/linux/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bravej/Documents/AnalyseImage/linux/opencv/release

# Utility rule file for opencv_perf_tests.

# Include the progress variables for this target.
include CMakeFiles/opencv_perf_tests.dir/progress.make

CMakeFiles/opencv_perf_tests:

opencv_perf_tests: CMakeFiles/opencv_perf_tests
opencv_perf_tests: CMakeFiles/opencv_perf_tests.dir/build.make
.PHONY : opencv_perf_tests

# Rule to build all files generated by this target.
CMakeFiles/opencv_perf_tests.dir/build: opencv_perf_tests
.PHONY : CMakeFiles/opencv_perf_tests.dir/build

CMakeFiles/opencv_perf_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_perf_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_perf_tests.dir/clean

CMakeFiles/opencv_perf_tests.dir/depend:
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bravej/Documents/AnalyseImage/linux/opencv /home/bravej/Documents/AnalyseImage/linux/opencv /home/bravej/Documents/AnalyseImage/linux/opencv/release /home/bravej/Documents/AnalyseImage/linux/opencv/release /home/bravej/Documents/AnalyseImage/linux/opencv/release/CMakeFiles/opencv_perf_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_perf_tests.dir/depend

