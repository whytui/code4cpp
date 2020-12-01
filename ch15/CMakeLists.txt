project(ch15)

message(STATUS "Generating ch15..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/singleton.h
        ${CMAKE_CURRENT_SOURCE_DIR}/singleton.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/observer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/observer.cpp
        )
add_executable(ch15 ${src})