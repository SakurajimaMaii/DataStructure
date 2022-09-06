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