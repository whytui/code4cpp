project(ch14)

message(STATUS "Generating ch14..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/new.cpp)
add_executable(ch14 ${src})