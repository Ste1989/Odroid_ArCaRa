# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build

# Include any dependencies generated for this target.
include realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/depend.make

# Include the progress variables for this target.
include realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/progress.make

# Include the compile flags for this target's objects.
include realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/flags.make

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/flags.make
realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o: /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src/realsense/realsense_camera/test/camera_core.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o"
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o -c /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src/realsense/realsense_camera/test/camera_core.cpp

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.i"
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src/realsense/realsense_camera/test/camera_core.cpp > CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.i

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.s"
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src/realsense/realsense_camera/test/camera_core.cpp -o CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.s

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.requires:
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.requires

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.provides: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.requires
	$(MAKE) -f realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/build.make realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.provides.build
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.provides

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.provides.build: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o

# Object files for target tests_camera_core
tests_camera_core_OBJECTS = \
"CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o"

# External object files for target tests_camera_core
tests_camera_core_EXTERNAL_OBJECTS =

/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/build.make
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libcv_bridge.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libimage_transport.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libcamera_info_manager.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libpcl_ros_filters.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libpcl_ros_io.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libpcl_ros_tf.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_common.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_kdtree.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_octree.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_search.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_surface.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_sample_consensus.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_filters.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_features.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_segmentation.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_io.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_registration.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_keypoints.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_recognition.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_visualization.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_people.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_outofcore.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_tracking.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libpcl_apps.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libqhull.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libOpenNI.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libvtkCommon.so.5.8.0
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libvtkRendering.so.5.8.0
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libvtkHybrid.so.5.8.0
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libvtkCharts.so.5.8.0
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libnodeletlib.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libbondcpp.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libclass_loader.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/libPocoFoundation.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libdl.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libroslib.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librosbag.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librosbag_storage.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libroslz4.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/liblz4.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libtopic_tools.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libtf.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libtf2_ros.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libactionlib.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libmessage_filters.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libroscpp.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libtf2.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librosconsole.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/liblog4cxx.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/librostime.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /opt/ros/indigo/lib/libcpp_common.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: gtest/libgtest.so
/home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core"
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests_camera_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/build: /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/devel/lib/realsense_camera/tests_camera_core
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/build

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/requires: realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/test/camera_core.cpp.o.requires
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/requires

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/clean:
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera && $(CMAKE_COMMAND) -P CMakeFiles/tests_camera_core.dir/cmake_clean.cmake
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/clean

realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/depend:
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/src/realsense/realsense_camera /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera /home/stefano/Progetto_Drone/Odroid_ArCaRa/NapoDrone_ws/build/realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : realsense/realsense_camera/CMakeFiles/tests_camera_core.dir/depend

