//
// Created by HP on 2021/9/21.
//

#ifndef DATASTRUCTURE_SEQQUEUE_H
#define DATASTRUCTURE_SEQQUEUE_H

#include<iostream>

const int Default_Max_Size = 50;

/**
 * 队列的实现
 * @tparam T
 */
template<class T>
class SeqQueue{
public:
    SeqQueue(int size = Default_Max_Size);
    ~SeqQueue();
    bool EnQueue(const T& x);
    bool DeQueue(T &x);
    bool GetFront(T &x);
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;

    template<T> friend ostream& operator<<(ostream& out, SeqQueue<T>& seqQueue);

protected:
    int rear = 0; //队尾
    int front = 0; //队头
    T *elements; //存放元素的数组
    int MaxSize; //队列最大容纳元素个数
};

/**
 * 构造函数
 * @tparam T
 * @param size
 */
template<class T>
SeqQueue<T>::SeqQueue(int size) {
    if(size<0){
        std::cerr << "输入的size范围错误"<<std::endl;
    }else{
        elements = new T[size];
        if(elements == NULL){
            std::cerr << "空间分配错误" << std::endl;
        }
        MaxSize = size;
    }
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
SeqQueue<T>::~SeqQueue() {
    delete []elements;
}

/**
 * 新元素入队
 * @tparam T
 * @param x 入队元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::EnQueue(const T &x) {
    if(IsFull()){
        return false;
    }else{
        elements[rear++] = x;
        return true;
    }
}

/**
 * 判断队列是否满
 * @tparam T
 * @return
 */
template<class T>
bool SeqQueue<T>::IsFull() const {
    return rear == MaxSize;
}

/**
 * 队头元素出栈
 * @tparam T
 * @param x 出栈元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::DeQueue(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front++];
    return true;
}

template<class T>
bool SeqQueue<T>::IsEmpty() const {
    return front == rear;
}

/**
 * 获取队头元素
 * @tparam T
 * @param x 获取到的元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::GetFront(T &x) {
    if(IsEmpty())
        return false;
    else
        x = elements[front];
    return true;
}

/**
 * 返回队列里面存储的元素个数
 * @tparam T
 * @return
 */
template<class T>
int SeqQueue<T>::getSize() const {
    return rear - front;
}

/**
 * 正序输出队列中的元素
 * @tparam T
 * @param out
 * @param seq
 * @return
 */
template<class T>
std::ostream &operator<<(std::ostream &out, SeqQueue<T> &seqQueue) {
    for(int i = seqQueue.front; i < seqQueue.rear; i++) {
        out << seqQueue.elements[i];
    }
    return out;
}

#endif //DATASTRUCTURE_SEQQUEUE_H