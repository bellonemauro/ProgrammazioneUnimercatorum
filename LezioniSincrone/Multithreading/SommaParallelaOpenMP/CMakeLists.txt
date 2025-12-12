#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  | Corso di Programmazione                                                   |
#  | Tutorial : Esempio Somma Parallela  con OpenMP                            |
#  |                                                                           |
#  | Authors: Mauro Bellone - http://www.maurobellone.com                      |
#  | Released under BDS License.                                               |
#  +---------------------------------------------------------------------------+ 

cmake_minimum_required(VERSION 3.10)
project(somma_parallela_openMP CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(somma_parallela_openMP main.cpp)

# Try to find OpenMP
find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found: enabling support")
    target_link_libraries(somma_parallela_openMP PUBLIC OpenMP::OpenMP_CXX)
else()
    message(WARNING "OpenMP not found: compiling without OpenMP support")
endif()
