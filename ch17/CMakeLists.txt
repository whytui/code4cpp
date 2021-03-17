project(ch17)

message(STATUS "Generating ch17..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/const.cpp)
add_executable(ch17 ${src})