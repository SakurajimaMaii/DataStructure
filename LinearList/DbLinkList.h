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

#ifndef DATA_DBLINKLIST_H
#define DATA_DBLINKLIST_H
/**
 * 双向链表节点定义
 * @tparam T
 */
template<class T>
struct DbLinkNode{
    T data;
    DbLinkNode<T>* prev; //前驱节点
    DbLinkNode<T>* next; //后继节点

    DbLinkNode(DbLinkNode<T>* left = nullptr,DbLinkNode<T>* right = nullptr):prev(left),next(right){}
    DbLinkNode(T value,DbLinkNode<T>* left = nullptr,DbLinkNode<T>* right = nullptr):data(value),prev(left),next(right){}
};

template<class T>
class DbLinkList{
private:
    DbLinkNode<T>* first;

public:
    DbLinkList();
    ~DbLinkList();
    int Length() const;
    bool IsEmpty() const;
    void setHead(DbLinkNode<T>* ptr);
    DbLinkNode<T> *Search(const T &x);
    DbLinkNode<T> *Locate(int i,int d);
    bool Insert(int i,const T &x,int d);
    bool Remove(int i,T &x,int d);
};

/**
 * 构造函数
 * @tparam T
 */
template<class T>
DbLinkList<T>::DbLinkList(){
    first = new DbLinkNode<T>();
    if(first==NULL){
        std::cerr << "空间分配错误" << std::endl;
    }else{
        first->next = first; //后继节点指向自己
        first->prev = first;
    }
}

/**
 * 获取双向循环链表的长度
 * @tparam T
 * @return 链表的长度，即储存的元素个数
 */
template<class T>
int DbLinkList<T>::Length() const {
    int length = 0;
    DbLinkNode<T>* node = first->next;
    while(node!=first){
        node = node->next;
        length++;
    }
    return length;
}

/**
 * 判断链表是否为空
 * @tparam T
 * @return true为空，false为不空
 */
template<class T>
bool DbLinkList<T>::IsEmpty() const {
    return first->next==first;
}

/**
 * 设置头节点
 * @tparam T
 * @param ptr
 */
template<class T>
void DbLinkList<T>::setHead(DbLinkNode<T> *ptr) {
    first = ptr;
}

/**
 * 在双向链表中以后继方向从头开始寻找值为x的结点地址
 * @tparam T
 * @param x 给定的元素值
 * @return 结点地址
 */
template<class T>
DbLinkNode<T> *DbLinkList<T>::Search(const T &x) {
    DbLinkNode<T>* node = first->next;
    while(node!=first){
        if(node->data == x)
            break;
        node = node->next;
    }
    if(node!=first)
        return node;
    else
        return NULL;
}

/**
 * 寻找链表序号为i的点
 * @tparam T
 * @param i
 * @param d d=0按照前驱方向寻找,d!=0按照后继节点寻找
 * @return
 */
template<class T>
DbLinkNode<T> *DbLinkList<T>::Locate(int i, int d) {
    if(first->next==first||i=0)
        return first;
    DbLinkNode<T> * current;
    if(d==0)
        current = first->prev; //搜索方向
    else
        current = first->next;
    for(int j = 1;j<i;j++){
        if(current == first)
            break;
        else if(d==0)
            current = current->prev;
        else
            current = current->next;
    }
    if(current!=first)
        return current;
    else
        return NULL;
}

/**
 * 在第i个节点后插入一个包含值为x的节点
 * @tparam T
 * @param i
 * @param x
 * @param d d=0按照前驱方向寻找,d!=0按照后继节点寻找
 * @return
 */
template<class T>
bool DbLinkList<T>::Insert(int i, const T &x, int d) {
    DbLinkNode<T>* node = Locate(i, d); //
    if()
}

template<class T>
bool DbLinkList<T>::Remove(int i, T &x, int d) {
    return false;
}

template<class T>
DbLinkList<T>::~DbLinkList() {
    delete first;
}

#endif //DATA_DBLINKLIST_H