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

#pragma once
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

int count_degree_0_leaf = 0;
int count_degree_1_leaf = 0;
int count_degree_2_leaf = 0;

template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T>* leftChild, * rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {}
	BinTreeNode(T value, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL) :data(value), leftChild(r), rightChild(r) {}
};

template<class T>
void Visit(BinTreeNode<T>* p) {
	cout << p->data;
}

template<class T>
class BinaryTree {
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(T value) :RefValue(value), root(NULL) {}
	BinaryTree(const BinaryTree<T>& BinTree);
	~BinaryTree() { destroy(root); }
	bool IsEmpty() { return root == NULL; }
	BinTreeNode<T>* Parent(BinTreeNode<T>* current) { //返回父节点
		return (root == NULL || root == current) ? NULL : Parent(root, current);
	}
	BinTreeNode<T>* LeftChild(BinTreeNode<T>* current) {
		return current == NULL ? current->leftChild : NULL;
	}
	BinTreeNode<T>* RightChild(BinTreeNode<T>* current) {
		return current == NULL ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }
	int Size() { return Size(root); }
	BinTreeNode<T>* getRoot()const { return root; }
	void preOrder(void(*visit)(BinTreeNode<T>* p) = &Visit) { preOrder(root, visit); }
	void inOrder(void(*visit)(BinTreeNode<T>* p) = &Visit) { inOrder(root, visit); }
	void postOrder(void(*visit)(BinTreeNode<T>* p) = &Visit) { postOrder(root, visit); }
	void levelOrder(void(*visit)(BinTreeNode<T>* p) = &Visit);
	//后序遍历法统计各个节点的度
	void countLeafDegree(BinTreeNode<T>* p);
	//交换两个孩子的节点
	void exchangeChild(BinTreeNode<T>* p);
	//求二叉树的宽度
	int getTreeWidth(BinTreeNode<T>* p);
	int getNodeLevel(BinTreeNode<T>* p, int height);
	//int Insert(const T& value);

protected:
	BinTreeNode<T>* root;
	T RefValue; //数据输入停止标志
	void CreateBinTree(istream& in, BinTreeNode<T>*& subTree);
	/*bool Insert(BinTreeNode<T>*& subTree, const T& x);*/
	void destroy(BinTreeNode<T>*& subTree);
	bool Find(BinTreeNode<T>* subTree, T x, const BinTreeNode<T>*& res)const;
	BinTreeNode<T>* Copy(BinTreeNode<T>* orignode);
	int Height(BinTreeNode<T>* subTree);
	int Size(BinTreeNode<T>* subTree)const; //返回结点数
	BinTreeNode<T>* Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current); //返回父节点
	void Traverse(BinTreeNode<T>* subTree, ostream& out); //前序遍历输出
	void preOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p));
	void inOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p));
	void postOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p));

    template<T> friend istream& operator>>(istream& in, BinaryTree<T>& Tree); //重载输入
    template<T> friend ostream& operator<<(ostream& out, BinaryTree<T>& Tree); //重载输出
    template<T> friend int operator==(const BinaryTree<T>& s, const BinaryTree<T>& t);
};

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& BinTree)
{
	root = Copy(BinTree.root);
}

template<class T>
void BinaryTree<T>::levelOrder(void(*visit)(BinTreeNode<T>* p))
{
	queue<BinTreeNode<T>*> myQueue;
	BinTreeNode<T>* p = root;
	myQueue.push(p);
	while (!myQueue.empty())
	{
		p = myQueue.front();
		myQueue.pop();
		visit(p);
		if (p->leftChild != NULL)
			myQueue.push(p->leftChild);
		if (p->rightChild != NULL)
			myQueue.push(p->rightChild);
	}
}

//使用广义表的方式建立二叉树
template<class T>
void BinaryTree<T>::CreateBinTree(istream& in, BinTreeNode<T>*& subTree)
{
	stack<BinTreeNode<T>*>s;
	subTree = NULL;
	BinTreeNode<T>* p, * t;
	int k = -1; //k为处理左右子树标记
	T ch;
	in >> ch;
	while (ch != RefValue)
	{
		switch (ch)
		{
		case '(':
			s.push(p);
			k = 1; //进入子树
			break;

		case ')':
			t = s.top();
			s.pop();
			break; //退出子树

		case ',':
			k = 2;
			break;

		default:
			p = new BinTreeNode<char>(ch);
			if (subTree == NULL) {
				subTree = p;
			}
			else if (k == 1) {
				t = s.top();
				t->leftChild = p;
			}
			else {
				t = s.top();
				t->rightChild = p;
			}
		}
		in >> ch;
	}
}

template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*& subTree)
{
	//如果subTree不为空，则递归删除其左右子树
	if (subTree != NULL) {
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}

template<class T>
bool BinaryTree<T>::Find(BinTreeNode<T>* subTree, T x, const BinTreeNode<T>*& res) const
{
	if (subTree == NULL)
		return false;
	if (subTree->data == x) {
		res = subTree;
		return true;
	}
	Find(subTree->leftChild, x, res);
	Find(subTree->rightChild, x, res);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orignode)
{
	if (orignode == NULL) {
		return NULL;
	}
	//创建根节点
	BinTreeNode<T> *temp = new BinTreeNode<T>();
	temp->data = orignode->data;
	temp->leftChild = Copy(orignode->leftChild); //复制左子树
	temp->rightChild = Copy(orignode->rightChild); //复制右子树
	return temp;
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)
		return 0;
	int left_height = Height(subTree->leftChild);
	int right_height = Height(subTree->rightChild);
	return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree)const
{
	if (subTree == NULL)
		return 0;
	return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current)
{
	//从subTree开始寻找current的父节点，如果找到则返回current的父节点，否则返回NULL
	if (subTree == NULL)
		return NULL;
	//subTree正好是current的父节点
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;
	BinTreeNode<T>* p;
	//这样写是由于函数只能有一个返回值
	if ((p = Parent(subTree->leftChild, current)) != NULL)
		return p; //递归在左子树中搜索
	else
		return Parent(subTree->rightChild, current); //递归在右子树中搜索
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, ostream& out)
{
	//搜素并输出根为subTree的二叉树
	if (subTree != NULL) {
		out << subTree->data << ' ';
		Traverse(subTree->leftChild, out);
		Traverse(subTree->rightChild, out);
	}
}

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p))
{
	if (p != NULL) { //递归结束条件
		visit(p);
		preOrder(p->leftChild, visit);
		preOrder(p->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p))
{
	if (p != NULL) { //递归结束条件
		inOrder(p->leftChild, visit);
		visit(p);
		inOrder(p->rightChild, visit);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* p, void(*visit)(BinTreeNode<T>* p))
{
	if (p != NULL) { //递归结束条件
		postOrder(p->leftChild, visit);
		postOrder(p->rightChild, visit);
		visit(p);
	}
}

template<class T>
istream& operator>>(istream& in, BinaryTree<T>& Tree)
{
	Tree.CreateBinTree(in, Tree.root);
	return in;
}

template<class T>
ostream& operator<<(ostream& out, BinaryTree<T>& Tree)
{
	out << "二叉树的前序遍历\n";
	Tree.Traverse(Tree.root, out);
	out << endl;
	return out;
}

template<class T>
int operator==(const BinaryTree<T>& s, const BinaryTree<T>& t) {
	return (equal(s.getRoot(), t.getRoot()));
}

template<class T>
bool equal(BinTreeNode<T>* s, BinTreeNode<T>* t)
{
	if (s == NULL && t == NULL)
		return true;
	else if (s != NULL && t != NULL && s->data == t->data && equal(s->leftChild, t->leftChild) && equal(s->rightChild, t->rightChild))
		return true;
	else
		return false;
}

template<class T>
void BinaryTree<T>::countLeafDegree(BinTreeNode<T>* p)
{
	if (p == NULL) {
		return;
	}
	else {
		countLeafDegree(p->leftChild);
		countLeafDegree(p->rightChild);
		//先处理度为0的再判断度为1的 顺序不能乱
		if (p->leftChild == NULL && p->rightChild == NULL) {
			count_degree_0_leaf++;
		}
		else if (p->leftChild == NULL || p->rightChild == NULL) {
			count_degree_1_leaf++;
		}
		else {
			count_degree_2_leaf++;
		}
	}
}

template<class T>
void BinaryTree<T>::exchangeChild(BinTreeNode<T>* p)
{
	if (p->leftChild != NULL)
		exchangeChild(p->leftChild);
	if (p->rightChild != NULL)
		exchangeChild(p->rightChild);
	BinTreeNode<T>* temp = p->leftChild;
	p->leftChild = p->rightChild;
	p->rightChild = temp;
}

template<class T>
int BinaryTree<T>::getTreeWidth(BinTreeNode<T>* p)
{
	//使用层序遍历的方法记录每层的个数
	if (p == NULL)
		return 0;
	queue<BinTreeNode<T>*> queue;
	queue.push(p);
	int curCountInQueue = 1;
	int maxWidth = 0;
	while (!queue.empty()) {
		curCountInQueue--;
		if (curCountInQueue == 0) {
			maxWidth = maxWidth > queue.size() ? maxWidth : queue.size();
			curCountInQueue = queue.size();
		}
		BinTreeNode<T>* temp = queue.front();
		queue.pop();
		if (temp->leftChild != NULL)
			queue.push(temp->leftChild);
		if (temp->rightChild != NULL)
			queue.push(temp->rightChild);
	}
	return maxWidth;
}

template<class T>
int BinaryTree<T>::getNodeLevel(BinTreeNode<T>* p, int height)
{
	int l;
	if (p == NULL)
		return 0;
	else {
		l = getNodeLevel(p->leftChild, height + 1);
		if (l != 0)
			return l;
		else
			return getNodeLevel(p->rightChild, height + 1);
	}
}