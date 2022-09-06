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
// Created by HP on 2021/9/29.
//

#ifndef DATASTRUCTURE_PRACTICE237_H
#define DATASTRUCTURE_PRACTICE237_H
#include "LinkList.h"
#include <iostream>

void problem_1(LinkNode<int> *&head,int x){
    LinkNode<int> *temp;

    if(head==NULL)
        return; //���Ϊ������ֹ����
    if(head->data==x){
        temp = head;
        head = head->next;
        delete temp;
        problem_1(head,x);
    }else{
        problem_1(head->next,x);
    }
}

void  problem_2(LinkList<int> &L,int value){
    LinkNode<int> *ptr = L.getHead()->next;
    LinkNode<int> *pre = L.getHead();
    LinkNode<int> *temp;
    while (ptr!=NULL){
        if(ptr->data==value){
            temp = ptr;
            ptr = ptr->next;
            pre->next = ptr;
            delete temp;
        }else{
            pre = ptr;
            ptr = ptr->next;
        }
    }
}

#endif //DATASTRUCTURE_PRACTICE237_H
