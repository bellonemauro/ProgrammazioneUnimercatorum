#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  | Corso di Programmazione                                                   |
#  | Tutorial : Esempio Giocatore                                              |
#  |                                                                           |
#  | Authors: Mauro Bellone - http://www.maurobellone.com                      |
#  | Released under BDS License.                                               |
#  +---------------------------------------------------------------------------+ 

cmake_minimum_required(VERSION 3.10)
project(Gioco)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aggiungi la libreria Giocatore
add_library(Giocatore
    libs/Giocatore/src/Giocatore.cpp
)

# Specifica dove trovare gli header
target_include_directories(Giocatore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/Giocatore/include
)

# Aggiungi l'eseguibile main
add_executable(main
    apps/buttonTest/main.cpp
)

# Collega la libreria Giocatore all'eseguibile
target_link_libraries(main PRIVATE Giocatore)
