# utils以静态库的方式嵌入
add_library(utils STATIC
        common.h
        utils.h
        file_util.cpp
        file_util.h
        socket.cpp
        socket.h
        date.cpp
        date.h
        file.h
        file.cpp
        )