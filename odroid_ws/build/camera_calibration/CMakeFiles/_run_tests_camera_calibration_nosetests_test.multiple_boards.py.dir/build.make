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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build

# Utility rule file for _run_tests_camera_calibration_nosetests_test.multiple_boards.py.

# Include the progress variables for this target.
include camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/progress.make

camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py:
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/camera_calibration && ../catkin_generated/env_cached.sh /usr/bin/python /opt/ros/indigo/share/catkin/cmake/test/run_tests.py /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/test_results/camera_calibration/nosetests-test.multiple_boards.py.xml /usr/local/bin/cmake\ -E\ make_directory\ /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/test_results/camera_calibration /usr/bin/nosetests-2.7\ -P\ --process-timeout=60\ /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/src/camera_calibration/test/multiple_boards.py\ --with-xunit\ --xunit-file=/home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/test_results/camera_calibration/nosetests-test.multiple_boards.py.xml

_run_tests_camera_calibration_nosetests_test.multiple_boards.py: camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py
_run_tests_camera_calibration_nosetests_test.multiple_boards.py: camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/build.make
.PHONY : _run_tests_camera_calibration_nosetests_test.multiple_boards.py

# Rule to build all files generated by this target.
camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/build: _run_tests_camera_calibration_nosetests_test.multiple_boards.py
.PHONY : camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/build

camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/clean:
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/camera_calibration && $(CMAKE_COMMAND) -P CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/cmake_clean.cmake
.PHONY : camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/clean

camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/depend:
	cd /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/src /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/src/camera_calibration /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/camera_calibration /home/stefano/Progetto_Drone/Odroid_ArCaRa/odroid_ws/build/camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : camera_calibration/CMakeFiles/_run_tests_camera_calibration_nosetests_test.multiple_boards.py.dir/depend

