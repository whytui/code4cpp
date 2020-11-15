project(algorithm)

message(STATUS "Generating algorithm..")

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/sort.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sort.h
        ${CMAKE_CURRENT_SOURCE_DIR}/array_list.h
        ${CMAKE_CURRENT_SOURCE_DIR}/list.h
        ${CMAKE_CURRENT_SOURCE_DIR}/error.h
        ${CMAKE_CURRENT_SOURCE_DIR}/linked_list.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/one_way_list.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/binary_tree.cpp)
add_executable(algorithm ${src})