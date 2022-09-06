#include "Stack.h"
#include <iostream>

template <class T>
struct StackNode
{
    T data;
    StackNode<T>* next;
    StackNode(StackNode<T>* ptr = NULL) :next(ptr) {};
    StackNode(const T& x, StackNode<T>* ptr = NULL) :data(x), next(ptr) {};
};

template <class T>
class LinkedStack {
public:
    LinkedStack();
    ~LinkedStack();
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x)const;
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;
    void makeEmpty();

    template<T> friend std::ostream& operator<<(std::ostream& out,LinkedStack<T>&s);

protected:
    //头指针不含有效数据
    StackNode<T>* top;
};

template<class T>
inline LinkedStack<T>::LinkedStack()
{
    top = new StackNode<T>();
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
inline LinkedStack<T>::~LinkedStack()
{
    makeEmpty();
}

/**
 * 进栈 头节点插入法
 * @tparam T
 * @param x 进栈元素
 */
template<class T>
inline void LinkedStack<T>::Push(const T& x)
{
    //因为链栈一般不会满,所以我们没必要做判断,直接插入即可
    StackNode<T>* p = new StackNode<T>(x);
    p->next = top->next;
    top->next = p;
}

/**
 * 出栈
 * @tparam T
 * @param x
 * @return
 */
template<class T>
inline bool LinkedStack<T>::Pop(T& x)
{
    if (IsEmpty()) {
        std::cerr << "当前栈为空" << std::endl;
        return false;
    }
    StackNode<T>* p = top->next; //目的是将退栈节点分离出来
    x = p->data;
    top->next = p->next;
    delete p;
    return false;
}

/**
 * 获取栈顶元素
 * @tparam T
 * @param x 栈顶元素
 * @return
 */
template<class T>
inline bool LinkedStack<T>::getTop(T& x) const
{
    if (IsEmpty()) {
        std::cerr << "当前栈为空" << std::endl;
        return false;
    }
    x = top->next->data;
    return true;
}

/**
 * 判断带头节点链表是否为空
 * @tparam T
 * @return 判断结果
 */
template<class T>
inline bool LinkedStack<T>::IsEmpty() const
{
    return top->next == NULL;
}

template<class T>
inline bool LinkedStack<T>::IsFull() const
{
    //链栈从某种意义上来说是不会满的,大小取决于内存的大小
    return false;
}

/**
 * 获取链栈中存储的元素个数
 * @tparam T
 * @return
 */
template<class T>
inline int LinkedStack<T>::getSize() const
{
    if(top==NULL)
        return 0;
    else{
        int count = 0;
        StackNode<T>* node = top->next;
        while(node!=NULL){
            node = node->next;
            count++;
        }
        return count;
    }
}

/**
 * 逐一删除栈中的节点
 * @tparam T
 */
template<class T>
void LinkedStack<T>::makeEmpty(){
    if(top==NULL)
        return;
    StackNode<T>* node;
    while(top!=NULL){
        node = top;
        top = top->next;
        delete top;
    }
}

/**
 * 输出函数重载
 * @tparam T
 * @param out 输出对象
 * @param s 链栈对象
 * @return
 */
template<class T>
std::ostream& operator<<(std::ostream& out,LinkedStack<T>&s) {
    out << "栈中的元素个数为：" << s.getSize() << std::endl;
    if (!s.IsEmpty()) {
        StackNode<T> *node = s.top->next;
        while (node != NULL) {
            out << node->data << std::endl;
            node = node->next;
        }
    }
    return out;
}