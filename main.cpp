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

//#include"CircLinkList.h"
#include"LinkList.h"
//#include"SeqStack.h"
//#include"LinkedStack.h"
//#include"Tree.h"
//#include"Sort.h"
//#include"SeqQueue.h"
//#include"CircQueue.h"
//#include"practice237.h"
#include<iostream>

void testLinkList(); //测试链表
void testCircleList(); //测试循环链表
void testSeqStack(); //测试顺序栈
void testLinkStack(); //测试链栈
void testTree(); //测试二叉树
void testSort(); //测试排序
void testSeqQueue(); //测试顺序队列
void testCircQueue(); //测试循环队列


int main() {
    testLinkList();
    return 0;
}

//void testCircleList(){
//    CircLinkList<int>* circ = new CircLinkList<int>();
//    std::cout << circ->Length();
//}

//void testSeqStack(){
//    SeqStack<int>* seq = new SeqStack<int>(20);
//    std::cout << seq->IsEmpty() << " ";
//    for (int i = 0; i < 30; i++)
//    {
//        seq->Push(i);
//    }
//    std::cout << seq->getSize() << std::endl;
//    for (int i = 0; i < 10; i++)
//    {
//        int j;
//        seq->getTop(j);
//        std::cout << seq->IsEmpty() << " ";
//    }
//}
//
//void testLinkStack(){
//    LinkedStack<int> * ls = new LinkedStack<int>();
//    for (int i = 0; i < 10; i++){
//        ls->Push(i);
//    }
//    std::cout << *ls;
//}
//
//void testTree(){
//    BinaryTree<char> binaryTree = BinaryTree<char>('#');
//    cin >> binaryTree;
//    binaryTree.preOrder();
//    cout << endl;
//    binaryTree.inOrder();
//    cout << endl;
//    binaryTree.postOrder();
//    cout << endl;
//    BinaryTree<char> binaryTree2 = BinaryTree<char>('#');
//    cin >> binaryTree2;
//    binaryTree2.preOrder();
//    cout << endl;
//    binaryTree2.inOrder();
//    cout << endl;
//    binaryTree2.postOrder();
//    //BinaryTree<char> binaryTree2 = BinaryTree<char>(binaryTree);
//    //binaryTree2.countLeafDegree(binaryTree2.getRoot());
//    //binaryTree2.exchangeChild(binaryTree2.getRoot());
//    //cout << binaryTree2.getTreeWidth(binaryTree2.getRoot());
//    //cout << binaryTree2.Size();
//    //cout << count_degree_0_leaf << endl;
//    //cout << count_degree_1_leaf << endl;
//    //cout << count_degree_2_leaf << endl;
//}
//
//void testSort() {
//    int array[10] = {9,8,7,6,5,4,3,2,1,0};
//    BubbleSort(array,10);
//    cout<<Array(array,10);
//}
//
//void testSeqQueue() {
//    SeqQueue<int>* seq = new SeqQueue<int>();
//
//    for (int i = 0; i < 10; ++i) {
//        seq->EnQueue(i);
//    }
//    cout<< *seq <<endl;
//    int value = -1;
//    seq->GetFront(value);
//    seq->DeQueue(value);
//    cout <<value << " " << seq->getSize();
//}
//
//void testCircQueue() {
//    CircQueue<int>* circ = new CircQueue<int>(20);
//    for (int i = 0; i < 10; ++i) {
//        circ->EnQueue(i);
//    }
//    cout << *circ;
//}

void testLinkList() {
    LinkList<int>* ll = new LinkList<int>();
    ll->Input();
    ll->output();
}