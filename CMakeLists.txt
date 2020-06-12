cmake_minimum_required(VERSION 3.15)
project(code4cpp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

link_libraries(ws2_32)

add_executable(code4cpp main.cpp ch01/ch01.cpp ch01/ch01.h main.h windows/win.cpp windows/win.h ch02/ch02.cpp ch02/ch02.h ch03/ch03.cpp ch03/ch03.h ch04/ch04.cpp ch04/book.cpp ch04/book.h ch04/ch04.h ch05/ch05.cpp ch05/ch05.h ch05/object.cpp ch05/object.h ch05/stack.cpp ch05/stack.h ch06/ch06.cpp ch06/ch06.h thread/thread.cpp thread/thread.h socket/socket.cpp socket/socket.h ch07/ch07.cpp ch07/ch07.cpp ch07/ch07.h utils/utils.cpp utils/utils.h utils/file_util.cpp utils/file_util.h utils/socket.cpp utils/socket.h ch08/ch08.cpp ch08/ch08.h windows/key_board.cpp windows/key_board.h ch08/rational.cpp ch08/rational.h ch09/ch09.cpp ch09/ch09.h ch09/geometricObj.cpp ch09/geometricObj.h ch09/deriveCircle.cpp ch09/deriveCircle.h ch10/ch10.cpp ch10/ch10.h ch11/ch11.cpp ch11/ch11.h ch11/findA.cpp ch01/input.cpp ch01/date.cpp ch01/random.cpp ch01/math.cpp ch01/string.cpp)