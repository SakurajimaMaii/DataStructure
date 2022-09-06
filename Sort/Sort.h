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

#ifndef SORT_H
#define SORT_H

#include<iostream>
#include"Sort.cpp"

void InsertionSort(int arr[], int len);
void BinaryInsertionSort(int arr[], int len);
void BubbleSort(int arr[], int len);
int QuickSortStandard(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
void SelectSort(int arr[], int len);

struct Array{
    int *arr;
    int length;

    Array(int arr[], int length):arr(arr), length(length){}
};

ostream& operator<<(ostream& out, const Array& array){
    for(int i = 0; i < array.length;i++){
        out<<array.arr[i]<<" ";
    }
    return out;
}
#endif