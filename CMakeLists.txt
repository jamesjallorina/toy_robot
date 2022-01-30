cmake_minimum_required(VERSION 3.16)

project (toy_robot)

file (GLOB_RECURSE toy_robot_SOURCES CONFIGURE_DEPENDS "source/*.cc")
file (GLOB_RECURSE toy_robot_HEADERS CONFIGURE_DEPENDS "source/*.hh")

set (toy_robot_INCLUDE_DIRS "")
foreach (_headerFile ${toy_robot_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND toy_robot_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES toy_robot_INCLUDE_DIRS)

add_executable(toy_robot ${toy_robot_SOURCES})
target_include_directories(toy_robot PRIVATE ${toy_robot_INCLUDE_DIRS})
