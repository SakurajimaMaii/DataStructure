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
// Created by HP on 2021/9/19.
//
#ifndef DATA_CIRCLINKLIST_H
#define DATA_CIRCLINKLIST_H

#include <iostream>

template<class T>
struct CircLinkNode{
    T data; //节点包含的数据元素
    CircLinkNode<T>* next; //指向后继节点

    CircLinkNode():data(),next(NULL){}
    CircLinkNode(T value):data(value),next(NULL) {}
};

/**
 * 带头节点的循环链表
 * @tparam T
 */
template<class T>
class CircLinkList{
private:
    CircLinkNode<T>* first;

public:
    CircLinkList();
    CircLinkList(CircLinkList &L);
    ~CircLinkList();
    int Length()const;
    bool IsEmpty()const;
    CircLinkNode<T>* getHead()const;
    CircLinkNode<T>* Search(T x);
    CircLinkNode<T>* Locate(int i);
    T getData(int i);
    void setData(int i,T & x);
    bool Insert(int i, T& x);
    bool Remove(int i,T &x);
};

/**
 * 构造函数
 */
template<class T>
CircLinkList<T>::CircLinkList(){
    first = new CircLinkNode<T>(); //为头节点分配空间
    if(first==NULL){
        std::cerr << "空间分配错误" <<std::endl;
    }else{
        first->next = first; //头指针指向自己
    }
}

/**
 * 计算链表的长度
 * @return
 */
template<class T>
int CircLinkList<T>::Length()const{
    int length = 0;
    CircLinkNode<T>* ptr = first;
    //当ptr指向first则说明是最后一个节点
    for (; ptr->next != first ; ptr = ptr->next) {
        length++;
    }
    return length;
}

template<class T>
CircLinkList<T>::CircLinkList(CircLinkList &L) {

}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
CircLinkList<T>::~CircLinkList() {

}

template<class T>
bool CircLinkList<T>::IsEmpty() const {
    return first->next == first;
}

template<class T>
CircLinkNode<T> *CircLinkList<T>::getHead() const {

}

template<class T>
CircLinkNode<T> *CircLinkList<T>::Search(T x) {
    return nullptr;
}

template<class T>
CircLinkNode<T> *CircLinkList<T>::Locate(int i) {
    return nullptr;
}

template<class T>
T CircLinkList<T>::getData(int i) {
    return nullptr;
}

template<class T>
void CircLinkList<T>::setData(int i, T &x) {

}

template<class T>
bool CircLinkList<T>::Insert(int i, T &x) {
    return false;
}

template<class T>
bool CircLinkList<T>::Remove(int i, T &x) {
    return false;
}

#endif //DATA_CIRCLINKLIST_H