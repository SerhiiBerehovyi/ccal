cmake_minimum_required(VERSION 3.26)
project(ccal C)

set(CMAKE_C_STANDARD 11)

add_executable(ccal src/main.c
        src/tools/tools.c
        includes/tools/tools.h
        src/ccal/datetime.c
        includes/ccal/datetime.h
        includes/ccal/datastructure.h
        src/ccal/calendar.c
        includes/ccal/calendar.h
        src/ccal/menu.c
        includes/ccal/menu.h
        includes/tools/escapesequenzen.h
        src/ccal/database.c
        includes/ccal/database.h
        src/ccal/sort.c
        includes/ccal/sort.h
        includes/ccal/list.h
        src/ccal/list.c
)
