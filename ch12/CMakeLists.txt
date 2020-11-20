project(ch12)

message(STATUS "Generating ch12..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/mutex.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ping.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ping.h
        ${CMAKE_CURRENT_SOURCE_DIR}/thread_pool.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/thread_pool.h)
add_executable(ch12 ${src})