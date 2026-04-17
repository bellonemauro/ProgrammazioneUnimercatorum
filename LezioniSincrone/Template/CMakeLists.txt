#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  | Corso di Programmazione                                                   |
#  | Tutorial : Esempii                                                        |
#  |                                                                           |
#  | Authors: Mauro Bellone - http://www.maurobellone.com                      |
#  | Released under BDS License.                                               |
#  +---------------------------------------------------------------------------+ 

cmake_minimum_required(VERSION 3.10)
project(lezSincrona_templates)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aggiungi la libreria Giocatore
#add_library(Giocatore
#    libs/Giocatore/src/Giocatore.cpp
#)

# Specifica dove trovare gli header
#target_include_directories(Giocatore PUBLIC
#    ${CMAKE_CURRENT_SOURCE_DIR}/libs/Giocatore/include
#)

# Aggiungi l'eseguibile main
add_executable(InventarioSenzaTemplate
    apps/InventarioSenzaTemplate/main.cpp
	apps/InventarioSenzaTemplate/armi.cpp
	apps/InventarioSenzaTemplate/pozioni.cpp
	apps/InventarioSenzaTemplate/inventarioArmi.cpp
	apps/InventarioSenzaTemplate/inventarioPozioni.cpp
)

# Aggiungi l'eseguibile main
add_executable(InventarioTemplate
    apps/InventarioTemplate/main.cpp
    apps/InventarioTemplate/armi.cpp
    apps/InventarioTemplate/pozioni.cpp
    apps/InventarioTemplate/inventario.cpp
)

# Aggiungi l'eseguibile main
add_executable(InventarioTemplatePolimorfico
    apps/InventarioTemplatePolimorfico/main.cpp
    apps/InventarioTemplatePolimorfico/inventario.cpp
    apps/InventarioTemplatePolimorfico/armi.cpp
    apps/InventarioTemplatePolimorfico/pozioni.cpp
)

# Collega la libreria Giocatore all'eseguibile
#target_link_libraries(InventarioSenzaTemplate PRIVATE Giocatore)
#target_link_libraries(InventarioTemplate PRIVATE Giocatore)
#target_link_libraries(InventarioTemplatePolimorfico PRIVATE Giocatore)