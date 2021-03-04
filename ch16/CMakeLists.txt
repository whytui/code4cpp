project(ch16)

message(STATUS "Generating ch16..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )
add_executable(ch16 ${src})