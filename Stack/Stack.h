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