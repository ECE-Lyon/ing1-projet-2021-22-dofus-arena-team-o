cmake_minimum_required(VERSION 3.20)
project(ing1_projet_2021_22_dofus_arena_team_o C)

set(CMAKE_C_STANDARD 11)

add_executable(ing1_projet_2021_22_dofus_arena_team_o
        main.c jeu.c jeu.h menu.c menu.h map.c map.h personnage.c personnage.h)

IF(WIN32)
    target_link_libraries(ing1_projet_2021_22_dofus_arena_team_o -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.7.0/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ing1_projet_2021_22_dofus_arena_team_o ${LIBRARIES})
ENDIF(WIN32)
