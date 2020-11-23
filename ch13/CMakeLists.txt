project(ch13)

message(STATUS "Generating ch13..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/create.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/create_class.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/thread_print.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/future.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/atomic.cpp mutex.cpp notify.cpp promise.cpp)
add_executable(ch13 ${src})