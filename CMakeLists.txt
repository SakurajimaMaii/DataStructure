cmake_minimum_required(VERSION 3.0)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

# 包含线性表目录
include_directories(LinearList)
# 包含栈目录
include_directories(Stack)
#包含队列目录
include_directories(Queue)
# 包含树目录
include_directories(Tree)
# 包含排序目录
include_directories(Sort)
# 测试题
include_directories(Practice)

add_executable(DataStructure main.cpp)
# 测试栈实现递归
add_executable(Recursion recursion.cpp)