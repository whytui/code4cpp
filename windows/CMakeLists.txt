project(windows)

message(STATUS "Generating windows..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )

add_executable(windows ${src})