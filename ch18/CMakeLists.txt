project(ch18)

message(STATUS "Generating ch18..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/objectBit.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/this.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/copyBuild.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/copy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/fuck.cpp
        )
add_executable(ch18 ${src})