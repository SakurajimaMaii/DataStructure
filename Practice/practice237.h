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
        return; //如果为空则终止运行
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
