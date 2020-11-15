project(windows)

message(STATUS "Generating windows..")

# windows环境
link_libraries(ws2_32)

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/socket_client.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/socket_client.h)
add_executable(windows ${src})