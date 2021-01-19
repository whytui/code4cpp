project(ch02)

message(STATUS "Generating ch02..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/ch02.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ch02.h
        ${CMAKE_CURRENT_SOURCE_DIR}/dir.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/maze.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/read.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/write.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/binary.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/platform.cpp)
add_executable(ch02 ${src})