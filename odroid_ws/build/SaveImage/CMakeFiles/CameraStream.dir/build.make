# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ste/Odroid_ArCaRa/odroid_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ste/Odroid_ArCaRa/odroid_ws/build

# Include any dependencies generated for this target.
include SaveImage/CMakeFiles/CameraStream.dir/depend.make

# Include the progress variables for this target.
include SaveImage/CMakeFiles/CameraStream.dir/progress.make

# Include the compile flags for this target's objects.
include SaveImage/CMakeFiles/CameraStream.dir/flags.make

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o: SaveImage/CMakeFiles/CameraStream.dir/flags.make
SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o: /home/ste/Odroid_ArCaRa/odroid_ws/src/SaveImage/src/CameraStream.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ste/Odroid_ArCaRa/odroid_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o"
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o -c /home/ste/Odroid_ArCaRa/odroid_ws/src/SaveImage/src/CameraStream.cpp

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CameraStream.dir/src/CameraStream.cpp.i"
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ste/Odroid_ArCaRa/odroid_ws/src/SaveImage/src/CameraStream.cpp > CMakeFiles/CameraStream.dir/src/CameraStream.cpp.i

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CameraStream.dir/src/CameraStream.cpp.s"
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ste/Odroid_ArCaRa/odroid_ws/src/SaveImage/src/CameraStream.cpp -o CMakeFiles/CameraStream.dir/src/CameraStream.cpp.s

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.requires:
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.requires

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.provides: SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.requires
	$(MAKE) -f SaveImage/CMakeFiles/CameraStream.dir/build.make SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.provides.build
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.provides

SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.provides.build: SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o

# Object files for target CameraStream
CameraStream_OBJECTS = \
"CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o"

# External object files for target CameraStream
CameraStream_EXTERNAL_OBJECTS =

/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_videostab.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_video.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_superres.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_stitching.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_photo.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ocl.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_objdetect.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_nonfree.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ml.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_legacy.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_imgproc.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_highgui.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_gpu.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_flann.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_features2d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_core.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_contrib.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_calib3d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libimage_transport.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libmessage_filters.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libtinyxml.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libclass_loader.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libPocoFoundation.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/x86_64-linux-gnu/libdl.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libroscpp.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_signals-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_filesystem-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libxmlrpcpp.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libroslib.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libcv_bridge.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_videostab.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_video.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_superres.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_stitching.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_photo.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ocl.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_objdetect.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_nonfree.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ml.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_legacy.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_imgproc.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_highgui.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_gpu.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_flann.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_features2d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_core.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_contrib.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_calib3d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/librosconsole.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/librosconsole_log4cxx.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/librosconsole_backend_interface.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/liblog4cxx.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_regex-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libroscpp_serialization.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/librostime.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_date_time-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_system-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/libboost_thread-mt.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libcpp_common.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libconsole_bridge.so
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_nonfree.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ocl.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_gpu.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_photo.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_objdetect.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_legacy.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_video.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_ml.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_calib3d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_features2d.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_highgui.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_imgproc.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_flann.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: /opt/ros/hydro/lib/libopencv_core.so.2.4.9
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: SaveImage/CMakeFiles/CameraStream.dir/build.make
/home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream: SaveImage/CMakeFiles/CameraStream.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream"
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CameraStream.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SaveImage/CMakeFiles/CameraStream.dir/build: /home/ste/Odroid_ArCaRa/odroid_ws/devel/lib/save_image/CameraStream
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/build

SaveImage/CMakeFiles/CameraStream.dir/requires: SaveImage/CMakeFiles/CameraStream.dir/src/CameraStream.cpp.o.requires
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/requires

SaveImage/CMakeFiles/CameraStream.dir/clean:
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage && $(CMAKE_COMMAND) -P CMakeFiles/CameraStream.dir/cmake_clean.cmake
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/clean

SaveImage/CMakeFiles/CameraStream.dir/depend:
	cd /home/ste/Odroid_ArCaRa/odroid_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ste/Odroid_ArCaRa/odroid_ws/src /home/ste/Odroid_ArCaRa/odroid_ws/src/SaveImage /home/ste/Odroid_ArCaRa/odroid_ws/build /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage /home/ste/Odroid_ArCaRa/odroid_ws/build/SaveImage/CMakeFiles/CameraStream.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SaveImage/CMakeFiles/CameraStream.dir/depend

