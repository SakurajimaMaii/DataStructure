//
// Created by HP on 2021/9/22.
//
// 本文件用来测试递归
#include"SeqStack.h"
#include<iostream>

long Fib(long n);

struct Node{
    long n; //记忆走过的n
    int tag; //区分左右递归 tag = 1左递归 tag = 2右递归

    Node():n(-1),tag(-1){}
};

int main(){
    std::cout << Fib(4);
}

long Fib(long n){
    SeqStack<Node> stack;
    Node* seq = new Node();
    long sum = 0;

    do{
        while(n>1){
            seq->n = n;
            seq->tag = 1;
            stack.Push(*seq);
            n--;
        }
        sum = sum+n;
        while(!stack.IsEmpty()){
            stack.Pop(*seq);
            if(seq->tag == 1){
                seq->tag = 2;
                stack.Push(*seq);
                n = seq->n-2;
                break;
            }
        }
    }while(!stack.IsEmpty());
    return sum;
}