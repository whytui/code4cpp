project(ch16)

message(STATUS "Generating ch16..")

if (UNIX OR Linux)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif ()

set(src
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/json.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/mysql.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/redis.cpp

        )
add_executable(ch16 ${src})

if (UNIX OR Linux)
    target_link_libraries(ch16 ${CONAN_LIBS})
    target_link_libraries(ch16 pthread)
endif ()