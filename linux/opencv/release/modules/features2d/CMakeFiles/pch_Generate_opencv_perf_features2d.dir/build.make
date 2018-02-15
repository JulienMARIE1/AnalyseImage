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

# Utility rule file for pch_Generate_opencv_perf_features2d.

# Include the progress variables for this target.
include modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/progress.make

modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d: modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch

modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch: ../modules/features2d/perf/perf_precomp.hpp
modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch: modules/features2d/perf_precomp.hpp
modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch: lib/libopencv_perf_features2d_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bravej/Documents/AnalyseImage/linux/opencv/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d && /usr/bin/cmake -E make_directory /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d/perf_precomp.hpp.gch
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG "-D__OPENCV_BUILD=1" "-D_USE_MATH_DEFINES" "-D__STDC_CONSTANT_MACROS" "-D__STDC_LIMIT_MACROS" "-D__STDC_FORMAT_MACROS" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/release" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/release" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/ts/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/features2d/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/imgcodecs/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/core/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/flann/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/imgproc/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/imgcodecs/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/videoio/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/highgui/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/core/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/imgproc/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/imgcodecs/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/videoio/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/highgui/include" -I"/home/bravej/Documents/AnalyseImage/linux/opencv/modules/features2d/perf" -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wuninitialized -Winit-self -Wno-narrowing -Wno-delete-non-virtual-dtor -Wno-comment -fdiagnostics-show-option -pthread -march=i686 -fomit-frame-pointer -ffunction-sections -fdata-sections -msse -msse2 -mfpmath=sse -fvisibility=hidden -fvisibility-inlines-hidden -fPIE -x c++-header -o /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d/perf_precomp.hpp

modules/features2d/perf_precomp.hpp: ../modules/features2d/perf/perf_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/bravej/Documents/AnalyseImage/linux/opencv/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating perf_precomp.hpp"
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d && /usr/bin/cmake -E copy_if_different /home/bravej/Documents/AnalyseImage/linux/opencv/modules/features2d/perf/perf_precomp.hpp /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d/perf_precomp.hpp

pch_Generate_opencv_perf_features2d: modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d
pch_Generate_opencv_perf_features2d: modules/features2d/perf_precomp.hpp.gch/opencv_perf_features2d_RELEASE.gch
pch_Generate_opencv_perf_features2d: modules/features2d/perf_precomp.hpp
pch_Generate_opencv_perf_features2d: modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/build.make
.PHONY : pch_Generate_opencv_perf_features2d

# Rule to build all files generated by this target.
modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/build: pch_Generate_opencv_perf_features2d
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/build

modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/clean:
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_perf_features2d.dir/cmake_clean.cmake
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/clean

modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/depend:
	cd /home/bravej/Documents/AnalyseImage/linux/opencv/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bravej/Documents/AnalyseImage/linux/opencv /home/bravej/Documents/AnalyseImage/linux/opencv/modules/features2d /home/bravej/Documents/AnalyseImage/linux/opencv/release /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d /home/bravej/Documents/AnalyseImage/linux/opencv/release/modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/features2d/CMakeFiles/pch_Generate_opencv_perf_features2d.dir/depend

