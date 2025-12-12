#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  | Corso di Programmazione                                                   |
#  | Tutorial : Esempio Somma Parallela                                        |
#  |                                                                           |
#  | Authors: Mauro Bellone - http://www.maurobellone.com                      |
#  | Released under BDS License.                                               |
#  +---------------------------------------------------------------------------+ 

cmake_minimum_required(VERSION 3.10)
project(somma_parallela CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(somma_parallela main.cpp)

