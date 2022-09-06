#ifndef STACK_H
#define STACK_H
/**
 * 栈的类定义
 * @tparam T
 */
template <class T>
class Stack {
	virtual void Push(const T& x) = 0; //新元素x进栈
	virtual bool Pop(T& x) = 0; //栈顶元素出栈,由x返回
	virtual bool getTop(T& x)const = 0; //获取栈顶元素
	virtual bool IsEmpty()const = 0; //判断栈是否为空
	virtual bool IsFull()const = 0; //判断是否栈满
	virtual int getSize()const = 0; //计算栈中的元素
};
#endif //STACK_H