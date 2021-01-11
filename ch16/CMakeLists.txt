project(ch16)

message(STATUS "Generating ch15..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dog.cpp
        )
add_executable(ch16 ${src})