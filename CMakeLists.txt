cmake_minimum_required(VERSION 3.17)
project(code4cpp VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

# -static-libgcc
set(CMAKE_EXE_LINKER_FLAGS "-finput-charset='utf8' -mcmodel=large")

get_filename_component(REDIS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
message(STATUS "Project root directory is: ${REDIS_ROOT}")

message(STATUS "${CMAKE_SYSTEM_NAME}")

add_executable(code4cpp main.cpp main.h)

# 03
message(STATUS "Generating CH03...")
set(CH03 ch03/ch03.cpp ch03/ch03.h ch03/point_arr.cpp ch03/dynamic_array.cpp)
add_executable(ch03 ${CH03})

# 04
message(STATUS "Generating CH04...")
set(CH04 ch04/ch04.h ch04/ch04.cpp ch04/book.cpp ch04/book.h ch04/union.cpp ch04/enum.cpp ch04/func.cpp)
add_executable(ch04 ${CH04})

# 05
message(STATUS "Generating CH05...")
set(CH05 ch05/ch05.cpp ch05/ch05.h ch05/object.cpp ch05/object.h ch05/stack.cpp ch05/stack.h)
add_executable(ch05 ${CH05})

# 06
message(STATUS "Generating CH06...")
set(CH06 ch06/auto.cpp ch06/ch06.cpp ch06/ch06.h ch06/free.cpp ch06/heap.cpp ch06/ptr.cpp ch06/func.cpp ch06/life.cpp)
add_executable(ch06 ${CH06})

# 07
message(STATUS "Generating CH07...")
set(CH07 ch07/ch07.cpp ch07/ch07.h ch07/rational.cpp ch07/rational.h ch07/operator.cpp)
add_executable(ch07 ${CH07})

# 08
message(STATUS "Generating CH08...")
set(CH08 ch08/ch08.cpp ch08/ch08.h ch08/spaces.cpp)
add_executable(ch08 ${CH08})

# 09
message(STATUS "Generating CH09...")
set(CH09 ch09/ch09.cpp ch09/ch09.h ch09/geometricObj.cpp ch09/geometricObj.h ch09/deriveCircle.cpp ch09/deriveCircle.h)
add_executable(ch09 ${CH09})

# 10
message(STATUS "Generating CH10...")
set(CH10 ch10/ch10.cpp ch10/ch10.h)
add_executable(ch10 ${CH10})

# 11
message(STATUS "Generating CH11...")
set(CH11 ch11/ch11.cpp ch11/ch11.h ch11/accumulate.cpp ch11/copy.cpp ch11/collection.cpp)
add_executable(ch11 ${CH11})

add_subdirectory(utils)
add_subdirectory(algorithm)
add_subdirectory(ch01)
add_subdirectory(ch02)
add_subdirectory(ch12)
add_subdirectory(ch13)
add_subdirectory(ch14)
add_subdirectory(ch15)
add_subdirectory(ch16)
add_subdirectory(ch17)
add_subdirectory(ch18)
add_subdirectory(windows)

target_include_directories(code4cpp
        PRIVATE ${REDIS_ROOT}/utils/lang
        PRIVATE ${REDIS_ROOT}/utils/net
        PRIVATE ${REDIS_ROOT}/utils/io)

target_link_libraries(code4cpp
        PRIVATE pthread
        PRIVATE m
        PRIVATE lang
        PRIVATE net
        PRIVATE io)

link_directories(utils/lang/ utils/net/ utils/io/)