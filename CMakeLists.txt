cmake_minimum_required(VERSION 3.5)
project( ADT-List VERSION 0.1 LANGUAGES CXX)


# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )
#CMAKE_CXX_FLAGS = "-Wall";

# set the include path

# -------------------------------
# This is for old cmake versions
# set (CMAKE_CXX_STANDARD 11)
# -------------------------------

#set include path
include_directories ( include )

# define the sources for the project

add_executable ( list_driver
				 src/driver_list.cpp ) #this is the application and has the main

# define C++11 standard
set_property (TARGET list_driver PROPERTY CXX_STANDARD 11)

#end
