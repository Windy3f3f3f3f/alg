#!/bin/bash

# 设置变量
SOURCE_FILE="hello.cpp"
EXECUTABLE="hello.out"
INPUT_FILE="a.in"

# 编译C++程序
g++ $SOURCE_FILE -static -O2 -std=c++14 -o $EXECUTABLE

# 检查编译是否成功
if [ $? -ne 0 ]; then
    echo "编译失败"
    exit 1
fi

# 运行程序并将输入文件的内容传递给它
./$EXECUTABLE < $INPUT_FILE

# 检查程序运行是否成功
if [ $? -ne 0 ]; then
    echo "程序运行失败"
    exit 1
fi
