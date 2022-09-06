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

#ifndef LINEARLIST_H
#define LINEARLIST_H

//线性表抽象基类
template<class T>
class LinearList {
public:
	virtual int Size()const = 0; //求表的最大体积
	virtual int Length()const = 0; //求表长度
	virtual int Search(T& x)const = 0; //在表中搜索给定值x，返回表项序号
	virtual int Locate(int i)const = 0; //在表中定位第i个元素位置，返回表项序号
	virtual bool getData(int i, T& x)const = 0; //取第i个表项的值
	virtual void setData(int i, T& x) = 0; //修改第i个表项的值
	virtual bool Insert(int i, T& x) = 0; //在第i个表项后插入x
	virtual bool Remove(int i, T& x) = 0; //删除第i个表项的，通过x返回
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual void input() = 0; //输入
	virtual void output() = 0; //输出
};
#endif