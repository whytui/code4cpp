# 如果开启DEBUG则-g生成调试信息
ifeq($(DEBUG),true)
CC=g++ -g
VERSION=debug
else
CC=g++
VERSION=release
endif

