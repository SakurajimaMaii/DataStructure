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
// Created by HP on 2021/9/22.
//
#include "Sort.h"
/**
 * 插入排序
 * @param arr 待排序的数组
 * @param len  待排序数组的长度
 */
void InsertionSort(int arr[], int len) {
    int tailIndex = 0; //用于指示已经排好序列结尾的下标
    int curIndex = 0; //用于指示待排数字的下标

    int curValue = 0; //保存待排关键字

    for (curIndex = 1; curIndex < len; curIndex++)
    {
        curValue = arr[curIndex];
        tailIndex = curIndex - 1;

        // 逐一遍历已经排好的序列，如果比待排关键字大就向后移动，直到空出待排关键字的位置
        while (tailIndex >= 0 && arr[tailIndex] > curValue)
        {
            arr[tailIndex + 1] = arr[tailIndex];
            tailIndex--;
        }

        arr[tailIndex + 1] = curValue; //找到位置将待排关键字插入
    }
}

/**
 * 折半插入排序
 * @param arr 待排序的数组
 * @param len  待排序数组的长度
 */
void BinaryInsertionSort(int arr[], int len)
{
    int tailIndex = 0; //用于指示已经排好序列结尾的下标
    int curIndex = 0; //用于指示待排数字的下标

    int curValue = 0; //保存待排关键字

    int low = 0, high = 0; //折半查找的范围

    int m;
    for (curIndex = 1; curIndex < len; curIndex++)
    {
        curValue = arr[curIndex];
        low = 0; high = curIndex - 1;

        //借助折半查找来找到应插入元素的位置
        while (low <= high)
        {
            m = (low + high) / 2;
            if (arr[m] > curValue)
                high = m - 1;
            else
                low = m + 1;
        }

        for (tailIndex = curIndex - 1; tailIndex >= high + 1; tailIndex--)
            arr[tailIndex + 1] = arr[tailIndex];
        arr[tailIndex + 1] = curIndex;
    }
}

/**
 * 冒泡排序
 * @param arr 待排序的数组
 * @param len  待排序数组的长度
 */
void BubbleSort(int arr[], int len) {
    int temp; //用于存放中间变量

    for (int i = 0; i < len - 1; i++) // 共len-1轮排序,每轮都是把最大的元素排在后面
    {
        for (int j = 0; j < len - 1 - i; j++) // 每轮排序中:需要比较的元素个数比上一轮少一个
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//对从arr[low]和arr[high]的关键字进行排序
int QuickSortStandard(int arr[], int low, int high) {
    int key = arr[low]; //基准值 默认是数组第一个数

    //下面这个循环完成了一趟排序，即将数组中小于temp的关键字放在左边，大于temp的关键字放在右边
    while (low < high) {
        //从右向左扫描，找到一个小于temp的关键字
        while (low < high && arr[high] >= key)
            --high;

        if (low < high) {
            arr[low] = arr[high]; //放在key左边
        }

        //从左向右扫描，找到一个大于temp的关键字
        while (low < high && arr[low] <= key)
            ++low;

        if (low < high) {
            arr[high] = arr[low]; //放在temp左边
        }
    }
    arr[low] = key;
    return low;
}

/**
 * 快速排序
 * @param arr
 * @param low
 * @param high
 */
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int standard = QuickSortStandard(arr, low, high);
        //左边排序
        QuickSort(arr, low, standard - 1);
        //右边排序
        QuickSort(arr, standard + 1, high);
    }
}

/**
 * 选择排序
 * @param arr 待排序的数组
 * @param len  待排序数组的长度
 */
void SelectSort(int arr[], int len) {
    int minValueIndex; //当前数组中的最小值索引

    for (int i = 0; i < len; i++)
    {
        minValueIndex = i;

        //找到数组中最小值的下标
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minValueIndex])
                minValueIndex = j;
        }

        //和无序序列第一个数值交换
        int temp = arr[minValueIndex];
        arr[minValueIndex] = arr[i];
        arr[i] = temp;
    }
}