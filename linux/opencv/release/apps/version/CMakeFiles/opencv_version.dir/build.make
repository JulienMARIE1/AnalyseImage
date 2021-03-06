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

# Include any dependencies generated for this target.
include apps/version/CMakeFiles/opencv_version.dir/depend.make

# Include the progress variables for this target.
include apps/version/CMakeFiles/opencv_version.dir/progress.make

# Include the compile flags for this target's objects.
include apps/version/CMakeFiles/opencv_version.dir/flags.make

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o: apps/version/CMakeFiles/opencv_version.dir/flags.make
apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o: ../apps/version/opencv_version.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bravej/Documents/AnalyseImage/linux/opencv/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_version.dir/opencv_version.cpp.o -c /home/bravej/Documents/AnalyseImage/linux/opencv/apps/version/opencv_version.cpp

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_version.dir/opencv_version.cpp.i"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/bravej/Documents/AnalyseImage/linux/opencv/apps/version/opencv_version.cpp > CMakeFiles/opencv_version.dir/opencv_version.cpp.i

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_version.dir/opencv_version.cpp.s"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/bravej/Documents/AnalyseImage/linux/opencv/apps/version/opencv_version.cpp -o CMakeFiles/opencv_version.dir/opencv_version.cpp.s

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.requires:
.PHONY : apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.requires

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.provides: apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.requires
	$(MAKE) -f apps/version/CMakeFiles/opencv_version.dir/build.make apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.provides.build
.PHONY : apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.provides

apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.provides.build: apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o

# Object files for target opencv_version
opencv_version_OBJECTS = \
"CMakeFiles/opencv_version.dir/opencv_version.cpp.o"

# External object files for target opencv_version
opencv_version_EXTERNAL_OBJECTS =

bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o
bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/build.make
bin/opencv_version: lib/libopencv_core.so.3.4.0
bin/opencv_version: lib/libopencv_highgui.so.3.4.0
bin/opencv_version: lib/libopencv_imgproc.so.3.4.0
bin/opencv_version: lib/libopencv_imgcodecs.so.3.4.0
bin/opencv_version: lib/libopencv_videoio.so.3.4.0
bin/opencv_version: lib/libopencv_imgcodecs.so.3.4.0
bin/opencv_version: lib/libopencv_imgproc.so.3.4.0
bin/opencv_version: lib/libopencv_core.so.3.4.0
bin/opencv_version: apps/version/CMakeFiles/opencv_version.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/opencv_version"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_version.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/version/CMakeFiles/opencv_version.dir/build: bin/opencv_version
.PHONY : apps/version/CMakeFiles/opencv_version.dir/build

apps/version/CMakeFiles/opencv_version.dir/requires: apps/version/CMakeFiles/opencv_version.dir/opencv_version.cpp.o.requires
.PHONY : apps/version/CMakeFiles/opencv_version.dir/requires

apps/version/CMakeFiles/opencv_version.dir/clean:
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version && $(CMAKE_COMMAND) -P CMakeFiles/opencv_version.dir/cmake_clean.cmake
.PHONY : apps/version/CMakeFiles/opencv_version.dir/clean

apps/version/CMakeFiles/opencv_version.dir/depend:
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bravej/Documents/AnalyseImage/linux/opencv /home/bravej/Documents/AnalyseImage/linux/opencv/apps/version /home/bravej/Documents/AnalyseImage/linux/opencv/release /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version /home/bravej/Documents/AnalyseImage/linux/opencv/release/apps/version/CMakeFiles/opencv_version.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/version/CMakeFiles/opencv_version.dir/depend

