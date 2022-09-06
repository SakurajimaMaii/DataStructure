#ifndef SEQLIST_H
#define SEQLIST_H

#include"LinearList.h"
#include<iostream>

const int defaultSize = 100;

template<class T>
class SeqList : public LinearList<T> {
private:
	int EmptyTag = -1; //顺序表为空的标识

protected:
	T* data; //存放数组
	int MaxSize; //可容纳最大表的项数
	int last; //当前已知表项的最后位置
	void reSize(int newSize); //改变data数组的大小

public:
    SeqList(int sz = defaultSize);
    SeqList(SeqList<T>& L);
	~SeqList() { delete[] data; };
	int Size()const;
	int Length()const;
	int Search(T& x)const;
	int Locate(int i)const;
	bool getData(int i, T& x)const;
	void setData(int i, T& x);
	bool Insert(int i, T& x); //在第i个表项后插入x
	bool Remove(int i, T& x); //删除第i个表项的，通过x返回
	bool IsEmpty()const; //判断顺序表是否为空
	bool IsFull()const; //判断顺序表是否为满
	void input(); //输入
	void output(); //输出
};

//重新分配线性表的大小
//@param newSize 新分配的大小
template<class T>
inline void SeqList<T>::reSize(int newSize)
{
    //如果新分配的空间大小范围合理
    if (newSize > 0 && newSize != MaxSize) {
        T* newArray = new T[newSize];
        if (newArray == NULL) {
            std::cerr << "空间分配错误" << std::endl;
        }
        else {
            int n = last + 1;
            T* newptr = newArray;
            T* oldptr = data;
            while (n--)
                *newptr++ = *oldptr; //进行元素复制
            delete[]data;
            data = newArray;
            MaxSize = newSize;
        }
    }
    else {
        std::cerr << "newSize大小错误" << std::endl;
    }
}

//构造函数
//@param sz 顺序表大小
template<class T>
inline SeqList<T>::SeqList(int sz)
{
    if (sz > 0) {
        MaxSize = sz;
        last = -1;
        data = new T[MaxSize];
        if (data == NULL) {
            std::cerr << "空间分配错误" << std::endl;
        }
    }
}

//复制构造参数
//@param L 待复制的线性表
template<class T>
inline SeqList<T>::SeqList(SeqList<T>& L)
{
    MaxSize = L.Size();
    last = L.Length() - 1;
    data = new T[MaxSize];

    if (data == NULL) {
        std::cerr << "空间分配错误" << std::endl;
    }
    else {
        T value;

        //这里i从1开始的原因参考Size的注释
        for (int index = 1; index < last; index++)
        {
            L.getData(index, value);
            data[index - 1] = value;
        }
    }
}

//求表的最大体积
//@return int 表的体积
template<class T>
inline int SeqList<T>::Size() const
{
    return MaxSize;
}

//求表的长度 表的长度(表长)是线性表中数据元素的数目
//@return int 表的长度
template<class T>
inline int SeqList<T>::Length() const
{
    return last + 1;
}

//搜索给定列表项在列表中的位置(从1开始计数)
//@param x 给定的数据元素
//@return int 元素在列表中的位置 返回0即为该项在列表中不存在
template<class T>
inline int SeqList<T>::Search(T& x) const
{
    for (int i = 0; i < last; i++) {
        if (data[i] == x)
            return i + 1;
    }
    return 0;
}

//返回列表项第i个元素的位置(从1开始)
//@return int 第i个元素的位置  如果是0表示定位失败
template<class T>
inline int SeqList<T>::Locate(int i) const
{
    if (i >= 0 && i < last + 1)
        return i;
    return 0;
}

//获取顺序表第i个元素
//@param i 元素位置（从1开始）
//@param x 获取到的元素
//@return bool 获取数据的结果
template<class T>
inline bool SeqList<T>::getData(int i, T& x) const
{
    if (Locate(i)) {
        x = data[i - 1];
        return true;
    }
    else {
        std::cout << "参数i范围错误" << std::endl;
        return false;
    }
}

//设置顺序表第i个元素
//@param i 元素位置（从1开始）
//@param x 设置的元素
template<class T>
inline void SeqList<T>::setData(int i, T& x)
{
    //元素的位置是否合法
    if (i > 0 && i <= last + 1) {
        data[i] = x;
    }
    else {
        std::cerr << "给定的元素范围非法" << std::endl;
    }
}

//在第i个位置后插入元素
//@param i 元素位置（从0开始到last+1 这里0是虚拟的）
//@param x 插入的元素
//@return bool 插入的结果
template<class T>
inline bool SeqList<T>::Insert(int i, T& x)
{
    if (last == MaxSize - 1) //表满的情况下无法插入
        return false;
    else if (i < 0 || i > last + 1) //输入的元素位置不合理
        return false;
    else {
        //将last到i位置的元素通通后移
        for (int index = last; index >= i; index--)
            data[index + 1] = data[index];
        data[i] = x;
        last++;
        return true;
    }
}

//删除第i个表项的，通过x返回
//@param i 表项的位置（从1开始到last+1）
//@param x 获取到的删除的元素
//@return bool 删除操作的结果
template<class T>
inline bool SeqList<T>::Remove(int i, T& x)
{
    if (last == -1) //空表不能删除
        return false;
    else if (i < 1 || i > last + 1) //输入的元素位置不合理
        return false;
    else {
        x = data[i - 1];
        for (int index = i; index <= last; index++)
            data[index - 1] = data[index];
        last--;
        return true;
    }
}

//顺序表是否为空
//@return bool
template<class T>
inline bool SeqList<T>::IsEmpty() const
{
    return last == EmptyTag;
}

//顺序表是否为满
//@return bool
template<class T>
inline bool SeqList<T>::IsFull() const
{
    return last == MaxSize - 1;
}

//依次输入元素个数
template<class T>
inline void SeqList<T>::input()
{
    int temp; //输入的元素个数
    std::cout << "请输入元素个数" << std::endl;
    std::cin >> temp;
    if (temp < 0 || temp > MaxSize)
        std::cerr << "输入的元素范围错误" << std::endl;
    else {
        std::cout << "请依次输入元素" << std::endl;
        for (int index = 0; index < temp; index++) {
            std::cin >> data[index];
        }
        last = temp - 1;
    }
}

//输出顺序表中的元素
template<class T>
inline void SeqList<T>::output()
{
    if (IsEmpty()) {
        std::cout << "当前顺序表为空" << std::endl;
    }
    else
    {
        for (int i = 0; i < last + 1; i++)
        {
            std::cout << data[i];
        }
    }
}

#endif