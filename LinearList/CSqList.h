#pragma once
#include<cstdlib>
//顺序表的默认大小
#define MaxSize 100

//顺序表的数据类型
typedef int ElemType;

//提前分配好大小
typedef struct {
    ElemType data[MaxSize]; //数据大小
    int length; //顺序表的长度
}SqList;

//自动分配大小
typedef struct {
    ElemType* data; //数据大小
    int length; //顺序表的长度
}SqList;