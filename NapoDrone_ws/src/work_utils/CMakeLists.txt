cmake_minimum_required(VERSION 2.8.3)
project(work_utils)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)



## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html


#catkin_install_python(PROGRAMS bin/hello DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)



add_executable(listener src/listener.cpp)
target_link_libraries(listener  ${catkin_LIBRARIES})
catkin_package()