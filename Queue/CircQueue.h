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

//
// Created by HP on 2021/9/22.
//
// 循环队列的实现
#ifndef DATASTRUCTURE_CIRCQUEUE_H
#define DATASTRUCTURE_CIRCQUEUE_H
#include<iostream>

template<class T>
class CircQueue{
public:
    CircQueue(int size);
    ~CircQueue();
    bool EnQueue(const T& x);
    bool DeQueue(T &x);
    bool GetFront(T &x);
    void makeEmpty();
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;

    template<T> friend std::ostream& operator<<(std::ostream& out, CircQueue<T>& circQueue);

protected:
    int front = 0; //队头指针
    int rear = 0; //队尾指针
    int *elements; //元素数组
    int MaxSize; //最大盛放的元素数组
};

template<class T>
CircQueue<T>::CircQueue(int size):front(0),rear(0),MaxSize(size) {
    elements = new T[MaxSize];
    if(elements == NULL)
        std::cerr << "空间分配错误" <<std::endl;
}

template<class T>
CircQueue<T>::~CircQueue() {
    delete []elements;
}

/**
 * 将元素插入到队尾,否则出错处理
 * @tparam T
 * @param x 进队元素
 * @return 操作结果
 */
template<class T>
bool CircQueue<T>::EnQueue(const T &x) {
    if(IsFull())
        return false;
    elements[rear] = x;
    rear = (rear + 1) % MaxSize;
    return true;
}

/**
 * 若队列不为空则删除队头元素并返回true,否则返回false
 * @tparam T
 * @param x
 * @return
 */
template<class T>
bool CircQueue<T>::DeQueue(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front];
    front = (front + 1) % MaxSize;
    return true;
}

template<class T>
bool CircQueue<T>::GetFront(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front];
    return true;
}

/**
 * 队头队尾指针置零
 * @tparam T
 */
template<class T>
void CircQueue<T>::makeEmpty() {
    front = rear = 0;
}

template<class T>
bool CircQueue<T>::IsEmpty() const {
    return front == rear;
}

template<class T>
bool CircQueue<T>::IsFull() const {
    return (rear + 1) % MaxSize == front;
}

/**
 * 求列表元素个数
 * @tparam T
 * @return
 */
template<class T>
int CircQueue<T>::getSize() const {
    return (rear - front + MaxSize) % MaxSize;
}

template<class T>
std::ostream &operator<<(std::ostream &out, CircQueue <T> &circQueue) {
    for (int i = circQueue.front; i < circQueue.rear; i++)  {
        out << circQueue.elements[i];
    }
    return out;
}
#endif //DATASTRUCTURE_CIRCQUEUE_H