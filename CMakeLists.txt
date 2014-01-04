########################################################################
#
# Project-wide settings

# Name of the project.
project(coding_interview)
cmake_minimum_required(VERSION 2.6.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Where .h files can be found.
include_directories(include)

# Where libraries can be found.
link_directories(lib)



# The name of our project is "HELLO". CMakeLists files in this project can 
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and 
# to the root binary directory of the project as ${HELLO_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.6) 
project (coding_interview) 

########################################################################
add_library (ci SHARED  src/common/binary_search_tree.cc)

########################################################################

# Make sure the linker can find the Hello library once it is built. 
link_directories (lib/ci) 

add_executable(
  ci_unittest 
  src/common/binary_search_tree_unittest.cc)

target_link_libraries (ci_unittest ci gtest gtest_main) 