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