#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>

/**
 * 声明链表节点
 * @tparam T
 * @param data 节点数据
 * @param next 指向下个节点指针
 */
template<class T>
struct LinkNode {
    T data;
    LinkNode<T> *next;

    LinkNode() : data(), next() {}
    LinkNode(T value) : data(value), next(nullptr) {}
};

/**
 * 顺序链表
 * @tparam T
 */
template<class T>
class LinkList {
private:
    LinkNode<T> *first; //头节点指针

public:
    LinkList();
    LinkList(LinkList<T> &L);
    ~LinkList() { makeEmpty();};
    void makeEmpty();
    LinkNode<T> *getHead() const;
    int Length() const;
    LinkNode<T> *Search(T x) const;
    LinkNode<T> *Search(LinkNode<T> *first,T &x) const;
    LinkNode<T> *Locate(int i) const;
    bool getData(int i, T &x) const;
    void setData(int i, T &x);
    bool Insert(int i, T &x); //在第i个表项后插入x
    bool Remove(int i, T &x); //删除第i个表项的，通过x返回
    bool IsEmpty() const; //判断顺序链表是否为满
    bool IsFull()const;
    void Input(); //输入
    void output(); //输出
};

/**
 * 初始化函数
 * @tparam T
 */
template<class T>
inline LinkList<T>::LinkList() {
    first = new LinkNode<T>();
    if (first == nullptr) {
        std::cerr << "链表节点分配错误" << std::endl;
    }
}

/**
 * 复制构造函数
 * @tparam T
 * @param L
 */
template<class T>
LinkList<T>::LinkList(LinkList<T> &L) {
    T value;
    LinkNode<T>* srcptr= L.getHead();
    LinkNode<T>* desptr= first = new LinkNode<T>();
    while (srcptr->next!=NULL){
        value = srcptr->next->data;
        desptr->next = new LinkNode<T>(value);
        srcptr = srcptr->next;
        desptr = desptr->next;
    }
}

/**
 * 获取头节点
 * @tparam T
 * @return 返回的头结点
 */
template<class T>
LinkNode<T> *LinkList<T>::getHead() const {
    return first;
}

/**
 * 返回链表存储的元素的个数
 * @tparam T
 * @return
 */
template<class T>
int LinkList<T>::Length() const {
    int length = 0;
    LinkNode<T> * node = first->next;
    while (node!=NULL) {
        length++;
        node = node->next;
    }
    return length;
}

/**
 * 搜索给定列表项的地址
 * @tparam T
 * @param x
 * @return 给定列表项的地址 返回NULL则代表查找失败
 */
template<class T>
LinkNode<T> *LinkList<T>::Search(T x) const {
    LinkNode<T> *desPtr = NULL;
    if (first != NULL) {
        for (desPtr = first->next; desPtr != NULL; desPtr = desPtr->next)
            if (desPtr->data == x)
                break;
    }
    return desPtr;
}



/**
 * 获取第i个元素的地址
 * @tparam T
 * @param i 元素序号 从1开始
 * @return 元素的地址 若返回NULL说明i太大
 */
template<class T>
LinkNode<T> *LinkList<T>::Locate(int i) const {
    LinkNode<T>* res = first;
    int index = 0;
    while (res!=NULL&&index<i) {
        res = res->next, index++;
    }
    return res;
}

/**
 * 正序输出链表中的元素
 * @tparam T
 */
template<class T>
inline void LinkList<T>::output() {
    LinkNode<T> *node = first->next;
    for (; node != NULL; node = node->next) {
        std::cout << node->data << " ";
    }
}

/**
 * 取出第i个元素的数值
 * @tparam T
 * @param i 从1开始
 * @param x 获取到的元素
 * @return 获取到的结果 false可能是链表为空或者给定的i过大
 */
template<class T>
inline bool LinkList<T>::getData(int i, T &x) const {
    if(IsEmpty())
        return false;
    else{
        int index = 0;
        LinkNode<T>* ptr = first;
        while (ptr!=NULL&&index<i) {
            ptr = ptr->next, index++;
        }
        if(ptr==NULL){ //i过大
            return false;
        }else{
            x = ptr->data;
            return true;
        }
    }
}

/**
 * 设定第i个元素的数值
 * @tparam T
 * @param i 从1开始
 * @param x 设定的元素
 */
template<class T>
void LinkList<T>::setData(int i, T &x) {
    if(i<0)
        return;
    LinkNode<T>* ptr = Locate(i);
    if(ptr==NULL)return;
    else
        ptr->data=x;
}

/**
 * 在第i个元素后面插入的x
 * @tparam T
 * @param i 从1开始
 * @param x 插入的元素
 * @return
 */
template<class T>
inline bool LinkList<T>::Insert(int i, T &x) {
    if(i<0)
        return false;
    else{
        LinkNode<T>* ptr = Locate(i);
        if(ptr==NULL)
            return false;
        else{
            LinkNode<T>* newNode = new LinkNode<T>(x);
            newNode->next = ptr->next;
            ptr->next = newNode;
            return true;
        }
    }
}

/**
 * 删除第i个元素的值
 * @tparam T
 * @param i
 * @param x 删除的元素
 * @return
 */
template<class T>
inline bool LinkList<T>::Remove(int i, T &x) {
    if(i<0)
        return false;
    else{
        LinkNode<T>* ptr = Locate(i-1); //获取前驱节点的地址
        if(ptr==NULL)
            return false;
        else{
            LinkNode<T>* node = ptr->next;
            ptr->next = node->next;
            x = node->data;
            delete node;
            return true;
        }
    }
}

/**
 * 判断顺序链表是否空 不会被调用
 * @tparam T
 * @return
 */
template<class T>
bool LinkList<T>::IsEmpty() const {
    return first->next == NULL;
}

/**
 * 依次向链表中输入元素 尾插法
 * @tparam T
 */
template<class T>
void LinkList<T>::Input() {
    int count = 0; //输入元素的个数
    std::cout << "请输入元素的个数" << std::endl;
    std::cin >> count;
    LinkNode<T> *node;
    LinkNode<T> *cur = first;
    std::cout << "请依次输入元素" << std::endl;
    int value = 0;
    for (int i = 0; i < count; i++) {
        std::cin >> value;
        node = new LinkNode<T>(value);
        cur->next = node;
        cur = node;
    }
}

/**
 * 清空链表
 * @tparam T
 */
template<class T>
void LinkList<T>::makeEmpty() {
    LinkNode<T>* ptr;
    while (first->next!=NULL){
        ptr = first->next;
        first->next = ptr->next;
        delete ptr;
    }
}

/**
 * 返回链表是否为满
 * @tparam T
 * @return
 */
template<class T>
bool LinkList<T>::IsFull() const {
    return false;
}

/**
 * 搜索算法的递归实现
 * @tparam T
 * @param first
 * @param x
 * @return
 */
template<class T>
LinkNode<T> *LinkList<T>::Search(LinkNode<T> *first, T &x) const {
    if(first==NULL)
        return NULL; //搜索失败
    else if(first->data==x)
        return first; //搜索成功
    else Search(first->next, x); //到下一结点继续搜索
}

#endif