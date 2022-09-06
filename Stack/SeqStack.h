// MIT License
//
// Copyright (c) 2022 Vast Gui
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef SEQSTACK_H
#define SEQSTACK_H

#include "Stack.h"
#include <iostream>
#include <cassert>

const int SEQSTACK_OVERFLOW_ADD_SIZE = 20; //栈溢出

template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);
    ~SeqStack();
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x) const;
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;

private:
    T *elements; //存放栈中元素数组
    int top;
    int MaxSize;
    void OverflowStack(); //栈的溢出处理
};

/**
 * 构造函数
 * @tparam T
 * @param sz
 */
template<class T>
SeqStack<T>::SeqStack(int sz):top(-1), MaxSize(sz)
{
    elements = new T[MaxSize];
    assert(elements!=NULL);
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
inline SeqStack<T>::~SeqStack()
{
    delete[]elements;
}

/**
 * 新元素进栈
 * @tparam T
 * @param x 进栈元素
 */
template<class T>
inline void SeqStack<T>::Push(const T& x)
{
    if (IsFull()) {
        OverflowStack();
    }
    elements[++top] = x;
}

/**
 * 栈顶元素出栈
 * @tparam T
 * @param x 返回的栈顶元素
 * @return 出栈操作结果
 */
template<class T>
inline bool SeqStack<T>::Pop(T& x)
{
    if (IsEmpty()) {
        std::cerr << "栈为空" << std::endl;
        return false;
    }
    x = elements[top--];
    return true;
}

/**
 * 获取栈顶元素
 * @tparam T
 * @param x 获取到的元素
 * @return 操作结果
 */
template<class T>
inline bool SeqStack<T>::getTop(T& x)const
{
    if (IsEmpty()) {
        std::cerr << "栈为空" << std::endl;
        return false;
    }
    x = elements[top];
    return true;
}

/**
 * 判断是否栈空
 * @tparam T
 * @return
 */
template<class T>
inline bool SeqStack<T>::IsEmpty()const
{
    return top == -1;
}

/**
 * 判断是否栈满
 * @tparam T
 * @return
 */
template<class T>
inline bool SeqStack<T>::IsFull()const
{
    return top == MaxSize - 1;
}

/**
 * 获取栈内元素的大小
 * @tparam T
 * @return
 */
template<class T>
inline int SeqStack<T>::getSize()const
{
    return top + 1;
}

/**
 * 栈的溢出处理
 * @tparam T
 */
template<class T>
void SeqStack<T>::OverflowStack() {
    T *newArray = new T[MaxSize + SEQSTACK_OVERFLOW_ADD_SIZE];
    if(newArray == NULL){
        std::cerr << "空间分配错误" << std::endl;
    }
    for(int i = 0; i < MaxSize;i++){
        newArray[i] = elements[i]; //复制原有栈中数据
    }
    MaxSize = MaxSize + SEQSTACK_OVERFLOW_ADD_SIZE;
    delete []elements;
    elements = newArray;
}

#endif //SEQSTACK_H