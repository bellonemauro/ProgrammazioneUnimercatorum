#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  | Corso di Programmazione                                                   |
#  | Tutorial : Esempio Benchmark convoluzione parallela                       |
#  |                                                                           |
#  | Authors: Mauro Bellone - http://www.maurobellone.com                      |
#  | Released under BDS License.                                               |
#  +---------------------------------------------------------------------------+ 

cmake_minimum_required(VERSION 3.10)
project(convoluzione_parallela CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(convoluzione_parallela main.cpp)

# Try to find OpenMP
find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found: enabling support")
    target_link_libraries(convoluzione_parallela PUBLIC OpenMP::OpenMP_CXX)
else()
    message(WARNING "OpenMP not found: compiling without OpenMP support")
endif()
