cmake_minimum_required(VERSION 3.10)
project(play-with-c)

set(CMAKE_C_STANDARD 11)

# Получаем список всех подпапок (где есть CMakeLists.txt)
file(GLOB SUBDIRECTORIES LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/*/)

foreach(SUBDIR ${SUBDIRECTORIES})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
        add_subdirectory(${SUBDIR})
        message(STATUS "Added subdirectory: ${SUBDIR}")
    endif()
endforeach()