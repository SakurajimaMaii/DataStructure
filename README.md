# 数据结构

## 1. 绪论

此部分主要考察以下内容

1. 数据结构的基本概念，数据的逻辑结构、存储结构
2. 算法的定义和应具有的特性，算法设计的要求，算法的时间复杂度分析和算法的空间复杂度分析。

### 1.1 数据结构基本概念

#### 1.1.1 数据结构的基本概念

数据结构由某一元素的数据集合和该集合中数据元素之间的关系组成：
$$DataStructure={D,R}$$
其中D是某一元素数据的集合，R是该集合中数据元素之间的关系的有限集合。

#### 1.1.2 数据的逻辑结构

==逻辑结构是指数据元素之间的逻辑关系，即从逻辑关系上描述数据==。它与数据的存储无关，是独立于计算机的。数据的逻辑结构分为线性结构和非线性结构，线性表是典型的线性结构；集合、树和图是典型的非线性结构。数据的逻辑结构分类如下图所示：
![数据的逻辑结构](http://c.biancheng.net/cpp/uploads/allimg/140707/1-140FGA042I2.jpg)

#### 1.1.3 数据的存储结构

==存储结构是指数据结构在计算机中的表示（又称映像）==，也称物理结构。它包括数据元素的表示和关系的表示。数据的存储结构是逻辑结构用计算机语言的实现，它依赖于计算机语言。数据的存储结构主要有：顺序存储、链式存储、索引存储和散列存储。

1) **顺序存储**：==把逻辑上相邻的元素存储在物理位置上也相邻的存储单元里，元素之间的关系由存储单元的邻接关系来体现==。其优点是可以实现随机存取，每个元素占用最少的存储空间；缺点是只能使用相邻的一整块存储单元，因此可能产生较多的外部碎片。

2) **链接存储**：==不要求逻辑上相邻的元素在物理位置上也相邻，**借助指示元素存储地址的指针表示元素之间的逻辑关系**==。其优点是不会出现碎片现象，充分利用所有存储单元；缺点是每个元素因存储指针而占用额外的存储空间，并且只能实现顺序存取。

3) **索引存储**：==在存储元素信息的同时，还建立附加的索引表。索引表中的每一项称为索引项，索引项的一般形式是：（关键字，地址）==。其优点是检索速度快；缺点是增加了附加的索引表，会占用较多的存储空间。另外，在增加和删除数据时要修改索引表，因而会花费较多的时间。

4) **散列存储**：==根据元素的关键字直接计算出该元素的存储地址，又称为Hash存储==。其优点是检索、增加和删除结点的操作都很快；缺点是如果散列函数不好可能出现元素存储单元的冲突，而解决冲突会增加时间和空间开销。

### 1.2 算法的分析与度量

#### 1.2.1 算法的定义

算法是一个**有穷**的指令集，这些指令为解决某一特殊问题而规定了运算序列。

#### 1.2.2 算法的特性

- 有输入
- 有输出
- 有穷性
- 确定性
- 能行性

>程序和算法不同，程序可以不满足有穷性

#### 1.2.3 算法设计要求

- 正确性(correctness)
  包括四方面：
  - 没有语法错误
  - 对于 合法的数据输入 能够产生满足要求的输出
  - 对于 非法的数据输入 能够得出满足规格说明的结果
  - 对于 特殊的数据输入 能够得出满足规格说明的结果

  其中
  非法的数据：比如输入的时间为负数，输入的距离为负数
  特殊的数据：比如输入的除数为0
- 可读性(readability)
  设计出来的算法要便于阅读、理解和交流。
- 健壮性(robustness)
  健壮性是指软件对于规范要求以外的输入情况的处理能力。
- 效率性(efficiency)
  较小的时间复杂度和空间复杂度

#### 1.2.4 算法的事前估计

算法复杂性的度量属于事前估计。可以分为空间复杂度和时间复杂度

- 空间复杂度(Space Complexity)
当问题的规模以某种单位从$1$增加到$n$时，解决这个问题的算法在执行时所占用的存储空间也以某种单位从$1$增加到$S(n)$,则称算法复杂度为$S(n)$。空间复杂度一般包含两个部分,程序代码本身占用的空间以及运算过程中与问题规模有关的变量占用的空间。

- 时间复杂度(Time Complexity)
当问题的规模以某种单位从$1$增加到$n$时，解决这个问题的算法在执行时所h耗费的时间也以某种单位从$1$增加到$T(n)$,则称算法复杂度为$T(n)$。

## 2. 线性表

此部分主要考察以下内容

1. 线性表的基本概念、特点、定义和基本操作；
2. 线性表的顺序存储结构，对其进行检索、插入和删除等操作；线性表的链式存储结构，单链表、双向链表和循环链表这三种链表形式的存储结构和特点以及基本操作；
3. 线性表的应用。

### 2.1 线性表的基本概念

- 由$n(n>=0)$个数据元素构成的==有限==序列,记作:
  $$L=(a_1,a_2,a_3,...,a_n)$$
  其中$a_1$是**首元素(head)**,$a_n$是**尾元素**
- 表的长度(表长)是线性表中数据元素的数目
- 空表指的是不包含数据元素的线性表
- 线性表是有限序列

### 2.2 线性表的特点

- 表中的==元素有限==
- 表中元素具有逻辑上的顺序性，表中元素有先后次序
- 表中元素都是数据元素，每个元素都是单个元素
- 表中数据元素类型都相同，这意味着每个元素都占用着相同大的存储空间
- 表中元素具有抽象性，仅仅讨论数据间的逻辑关系，而不考虑数据表示的内容

### 2.3 线性表的定义

```cpp
//线性表抽象基类
template<class T>
class LinearList {
public:
  LinearList();
  ~LinearList();

  virtual int Size()const = 0; //求表的最大体积
  virtual int Length()const = 0; //求表长度
  virtual int Search(T& x)const = 0; //在表中搜索给定值x，返回表项序号
  virtual int Locate(int i)const = 0; //在表中定位第i个元素位置，返回表项序号
  virtual bool getData(int i, T& x)const = 0; //取第i个表项的值
  virtual void setData(int i, T& x) = 0; //修改第i个表项的值
  virtual bool Insert(int i, T& x) = 0; //在第i个表项后插入x
  virtual bool Remove(int i, T& x) = 0; //删除第i个表项的，通过x返回
  virtual bool IsEmpty()const = 0;
  virtual bool IsFull()const = 0;
  virtual void Sort() = 0; //排序
  virtual void input() = 0; //输入
  virtual void output() = 0; //输出
  virtual LinearList<T> operator = (LinearList<T>& L) = 0; //复制
};
```

### 2.4 线性表的顺序存储结构

顺序表是线性表基于数组的实现,特点是==用物理位置上的临接关系来表示节点间的关系==

#### 2.4.1 顺序表的定义

```cpp
//提前分配好大小
typedef struct {
  ElemType data[MaxSize]; //数据大小
  int length; //顺序表的长度
}SqList;

//自动分配大小
typedef struct {
  ElemType *data; //数据大小
  int length; //顺序表的长度
}SqList;
```

```cpp
template<class T>
class SeqList :public LinearList<T> {
protected:
  T* data; //存放数组
  int MaxSize; //可容纳最大表的项数
  int last; //当前已知表项的最后位置
  void reSize(int newSize); //改变data数组的大小

  public:
  SeqList(int sz = defaultSize);
  SeqList(SeqList<T>& L);
  ~SeqList() { delete[] data; };
  int Size()const;
  int Length()const;
  int Search(T& x)const;
  int Locate(int i)const;
  bool getData(int i, T& x)const;
  void setData(int i, T& x);
  bool Insert(int i, T& x); //在第i个表项后插入x
  bool Remove(int i, T& x); //删除第i个表项的，通过x返回
  bool IsEmpty()const; //判断顺序表是否为空
  bool IsFull()const; //判断顺序表是否为满
  void Sort(); //排序
  void input(); //输入
  void output(); //输出
  SeqList<T> operator = (SeqList<T>& L); //复制
  void Union(SeqList<T>& LA, SeqList<T>& LB);
  void Intersection(SeqList<T>& LA, SeqList<T>& LB);
};
```

#### 2.4.2 顺序表的操作

插入操作

```cpp
//在第i个位置后插入元素
//@param i 元素位置（从0开始到last+1）
//@param x 插入的元素
//@return bool 插入的结果
template<class T>
inline bool SeqList<T>::Insert(int i, T& x)
{
  if (last == MaxSize - 1) //表满的情况下无法插入
    return false;
  else if (i < 0 || i > last + 1) //输入的元素位置不合理
    return false;
  else {
    //将last到i位置的元素通通后移
    for (int index = last; index >= i; index--)
      data[index + 1] = data[index];
    data[i] = x;
    last++;
    return true;
  }
}
```

删除操作

```cpp
//删除第i个表项的，通过x返回
//@param i 表项的位置（从1开始到last+1）
//@param x 获取到的删除的元素
//@return bool 删除操作的结果
template<class T>
inline bool SeqList<T>::Remove(int i, T& x)
{
  if (last == -1) //空表不能删除
    return false;
  else if (i < 1 || i > last + 1) //输入的元素位置不合理
    return false;
  else {
    x = data[i - 1];
    for (int index = i; index <= last; index++)
      data[index - 1] = data[index];
    last--;
    return true;
  }
}
```

检索操作

```cpp
//返回列表项第i个元素的位置(从1开始)
//@return int 第i个元素的位置  如果是0表示定位失败
template<class T>
inline int SeqList<T>::Locate(int i) const
{
  if (i >= 0 && i < last + 1)
    return i;
  return 0;
}

//获取顺序表第i个元素
//@param i 元素位置（从1开始）
//@param x 获取到的元素
//@return bool 获取数据的结果
template<class T>
inline bool SeqList<T>::getData(int i, T& x) const
{
  if (Locate(i)) {
    x = data[i - 1];
    return true;
  }
  else {
    cout << "参数i范围错误" << endl;
    return false;
  }
}
```

输入元素

```cpp
//依次输入元素个数
template<class T>
inline void SeqList<T>::input()
{
  int temp; //输入的元素个数
  cout << "请输入元素个数" << endl;
  cin >> temp;
  if (temp < 0 || temp > MaxSize)
    cerr << "输入的元素范围错误" << endl;
  else {
    cout << "请依次输入元素" << endl;
    for (int index = 0; index < temp; index++) {
      cin >> data[index];
    }
    last = temp - 1;
  }
}
```

输出元素

```cpp
//输出顺序表中的元素
template<class T>
inline void SeqList<T>::output()
{
  if (IsEmpty()) {
    cout << "当前顺序表为空" << endl;
  }
  else
  {
    for (int i = 0; i < last + 1; i++)
    {
      cout << data[i];
    }
  }
}
```

### 2.5 线性表的链式结构

#### 2.5.1 单链表

单链表的特点是长度可以很方便的进行扩充，同时线性表中数据元素的顺序和其链表的物理顺序可能不一样。一般通过指针联系。

单链表的形式

![单链表的形式](https://bkimg.cdn.bcebos.com/pic/50da81cb39dbb6fdeb24c8ab0324ab18972b373b?x-bce-process=image/watermark,image_d2F0ZXIvYmFpa2U4MA==,g_7,xp_5,yp_5/format,f_auto)
>上图来源于百度

##### 2.5.1.1 单链表定义

节点定义

```cpp
/**
 * 声明链表节点
 * @tparam T
 * @param data 节点数据
 * @param next 指向下个节点指针
 */
template<class T>
struct LinkNode {
    T data;
    LinkNode<T>* next;

    LinkNode() :data(), next() {}
    LinkNode(T value) :data(value), next(NULL) {}
};
```

类定义

```cpp
/**
 * 顺序链表
 * @tparam T
 */
template<class T>
class LinkList {
private:
    int EmptyTag = 0;

protected:
    LinkNode<T>* first; //头节点指针
    int length; //链表存储元素的个数

public:
    LinkList();
    LinkList(LinkList<T>& L);
    ~LinkList() { delete first; length = EmptyTag; };
    int Size()const;
    int Length()const;
    int Search(T& x)const;
    int Locate(int i)const;
    bool getData(int i, T& x)const;
    void setData(int i, T& x);
    bool Insert(int i, T& x); //在第i个表项后插入x
    bool Remove(int i, T& x); //删除第i个表项的，通过x返回

    bool IsFull()const; //判断顺序链表是否为满
    void input(); //输入
    void output(); //输出
};
```

##### 2.5.1.2 单链表操作

构造函数

```cpp
/**
 * 初始化函数
 * @tparam T
 */
template<class T>
inline LinkList<T>::LinkList() {
    first = new LinkNode<T>();
    if (first == nullptr) {
        std::cerr << "链表节点分配错误" << std::endl;
    }
}
```

复制构造函数

```cpp
/**
 * 复制构造函数
 * @tparam T
 * @param L
 */
template<class T>
LinkList<T>::LinkList(LinkList<T> &L) {
    T value;
    LinkNode<T>* srcptr= L.getHead();
    LinkNode<T>* destptr= first = new LinkNode<T>();
    while (srcptr->next!=NULL){
        value = srcptr->next->data;
        destptr->next = new LinkNode<T>(value);
        srcptr = srcptr->next;
        destptr = destptr->next;
    }
}
```

获取头节点

```cpp
/**
 * 获取头节点
 * @tparam T
 * @return 返回的头结点
 */
template<class T>
LinkNode<T> *LinkList<T>::getHead() const {
    return first;
}
```

获取链表长度

```cpp
/**
 * 返回链表存储的元素的个数
 * @tparam T
 * @return
 */
template<class T>
int LinkList<T>::Length() const {
    int length = 0;
    LinkNode<T> * node = first->next;
    while (node!=NULL) {
        length++;
        node = node->next;
    }
    return length;
}
```

查找指定元素

```cpp
/**
 * 搜索给定列表项的地址
 * @tparam T
 * @param x
 * @return 给定列表项的地址 返回NULL则代表查找失败
 */
template<class T>
LinkNode<T> *LinkList<T>::Search(T x) const {
    LinkNode<T> *desPtr = NULL;
    if (first != NULL) {
        for (desPtr = first->next; desPtr != NULL; desPtr = desPtr->next)
            if (desPtr->data == x)
                break;
    }
    return desPtr;
}
```

获取指定位置元素的地址

```cpp
/**
 * 获取第i个元素的地址
 * @tparam T
 * @param i 元素序号 从1开始
 * @return 元素的地址 若返回NULL说明i太大
 */
template<class T>
LinkNode<T> *LinkList<T>::Locate(int i) const {
    LinkNode<T>* res = first;
    int index = 0;
    while (res!=NULL&&index<i) {
        res = res->next, index++;
    }
    return res;
}
```

正序输出链表中的元素

```cpp
/**
 * 正序输出链表中的元素
 * @tparam T
 */
template<class T>
inline void LinkList<T>::output() {
    LinkNode<T> *head = first->next;
    for (; head != NULL; head = head->next) {
        std::cout << head->data << " ";
    }
}
```

取出第i个元素的数值

```cpp
/**
 * 取出第i个元素的数值
 * @tparam T
 * @param i 从1开始
 * @param x 获取到的元素
 * @return 获取到的结果 false可能是链表为空或者给定的i过大
 */
template<class T>
inline bool LinkList<T>::getData(int i, T &x) const {
    if(IsEmpty())
        return false;
    else{
        int index = 0;
        LinkNode<T>* ptr = first;
        while (ptr!=NULL&&index<i) {
            ptr = ptr->next, index++;
        }
        if(ptr==NULL){ //i过大
            return false;
        }else{
            x = ptr->data;
            return true;
        }
    }
}
```

设定第i个元素的数值

```cpp
/**
 * 设定第i个元素的数值
 * @tparam T
 * @param i
 * @param x 设定的元素
 */
template<class T>
void LinkList<T>::setData(int i, T &x) {
    if(i<0)
        return;
    LinkNode<T>* ptr = Locate(i);
    if(ptr==NULL)return;
    else
        ptr->data=x;
}
```

在第i个元素后面插入的x

```cpp
/**
 * 在第i个元素后面插入的x
 * @tparam T
 * @param i 从1开始
 * @param x 插入的元素
 * @return
 */
template<class T>
inline bool LinkList<T>::Insert(int i, T &x) {
    if(i<0)
        return false;
    else{
        LinkNode<T>* ptr = Locate(i);
        if(ptr==NULL)
            return false;
        else{
            LinkNode<T>* newNode = new LinkNode<T>(x);
            newNode->next = ptr->next;
            ptr->next = newNode;
            return true;
        }
    }
}
```

删除第i个元素的值

```cpp
/**
 * 删除第i个元素的值
 * @tparam T
 * @param i
 * @param x 删除的元素
 * @return
 */
template<class T>
inline bool LinkList<T>::Remove(int i, T &x) {
    if(i<0)
        return false;
    else{
        LinkNode<T>* ptr = Locate(i-1); //获取前驱节点的地址
        if(ptr==NULL)
            return false;
        else{
            LinkNode<T>* node = ptr->next;
            ptr->next = node->next;
            x = node->data;
            delete node;
            return true;
        }
    }
}
```

插入元素
$$\begin{cases}
前插法建立单链表 \\
后插法建立单链表
\end{cases}$$

```cpp
/**
 * 依次向链表中输入元素 尾插法
 * @tparam T
 */
template<class T>
void LinkList<T>::Input() {
    int count = 0; //输入元素的个数
    std::cout << "请输入元素的个数" << std::endl;
    std::cin >> count;
    LinkNode<T> *node;
    LinkNode<T> *cur = first;
    std::cout << "请依次输入元素" << std::endl;
    int value = 0;
    for (int i = 0; i < count; i++) {
        std::cin >> value;
        node = new LinkNode<T>(value);
        cur->next = node;
        cur = node;
    }
}
```

#### 2.5.2 线性链表的其他变形

##### 2.5.2.1 循环链表

循环链表也是采用==链式存储==,与单链表不相同的是链表尾节点指向的不是NULL而是链表的头节点，这样只要我们知道其中任何一个节点的地址就能遍历链表中其他任意节点。

![循环链表示意图](https://img-blog.csdn.net/20170715205533750)
>上图来源于[单向循环链表的简单实现](https://blog.csdn.net/sinat_39061823/article/details/74935755)

对于单链表,我们判断该节点是否为尾节点使用下列方式

```cpp
current->next==NULL
```

而对于循环链表，我们需要使用

```cpp
current->next==first //first即头节点
```

###### 2.5.2.1.1 循环链表的类定义

节点定义

```cpp
template<class T>
struct CircLinkNode{
    T data; //节点包含的数据元素
    CircLinkNode<T>* next; //指向后继节点

    CircLinkNode():data(),next(NULL){}
    CircLinkNode(T value):data(value),next(NULL) {}
};
```

类定义

```cpp
/**
 * 带头节点的循环链表
 * @tparam T
 */
template<class T>
class CircLinkList{
private:
    CircLinkNode<T>* first;

public:
    CircLinkList();
    CircLinkList(CircLinkList &L);
    ~CircLinkList();
    int Length()const;
    bool IsEmpty()const;
    CircLinkNode<T>* getHead()const;
    CircLinkNode<T>* Search(T x);
    CircLinkNode<T>* Locate(int i);
    T getData(int i);
    void setData(int i,T & x);
    bool Insert(int i, T& x);
    bool Remove(int i,T &x);
};
```

###### 2.5.2.1.2 循环链表的操作

以下只展示了部分操作

构造函数

```cpp
/**
 * 构造函数
 */
template<class T>
CircLinkList<T>::CircLinkList(){
    first = new CircLinkNode<T>(); //为头节点分配空间
    if(first==NULL){
        std::cerr << "空间分配错误" <<std::endl;
    }else{
        first->next = first; //头指针指向自己
    }
}
```

##### 2.5.2.2 双向链表

> 本部分参考资料[双链表](https://www.yiibai.com/data_structure/doubly-linked-list.html)

双向链表主要是为了解决链表中访问**直接前驱**和**直接后继**的问题

双向链表相对于单链表，其==删除==和==插入==操作的时间复杂度都是$O(1)$

###### 2.5.2.2.1 双向链表的定义

双向链表的节点包含指向序列中前一个节点和下一个节点的指针。 因此，在双向链表中，节点由三部分组成：节点数据，指向下一个节点的指针(next指针)，指向前一个节点的指针(prev指针)。 双向链表中的示例节点如下图所示。

![双向链表节点示意图](https://www.yiibai.com/uploads/article/2018/11/07/104421_43592.png)

由图示我们可以得到下列关系

```cpp
p->Prev->Next = p->Next->Prev = p
```

###### 2.5.2.2.2 带附加头节点双向链表的定义

节点定义

```cpp
/**
 * 双向链表节点定义
 * @tparam T
 */
template<class T>
struct DbLinkNode{
    T data;
    DbLinkNode<T>* prev; //前驱节点
    DbLinkNode<T>* next; //后继节点

    DbLinkNode(DbLinkNode<T>* left = nullptr,DbLinkNode<T>* right = nullptr):prev(left),next(right){}
    DbLinkNode(T value,DbLinkNode<T>* left = nullptr,DbLinkNode<T>* right = nullptr):data(value),prev(left),next(right){}
};
```

类定义

```cpp
template<class T>
class DbLinkList{
private:
    DbLinkNode<T>* first;

public:
    DbLinkList();
    ~DbLinkList();
    int Length() const;
    bool IsEmpty() const;
    void setHead(DbLinkNode<T>* ptr);
    DbLinkNode<T> *Search(const T &x);
    DbLinkNode<T> *Locate(int i,int d);
    bool Insert(int i,const T &x,int d);
    bool Remove(int i,T &x,int d);
};
```

###### 2.5.2.2.3 带附加头节点双向链表的操作

构造函数

```cpp
/**
 * 构造函数
 * @tparam T
 */
template<class T>
DbLinkList<T>::DbLinkList(){
    first = new DbLinkNode<T>();
    if(first==NULL){
        std::cerr << "空间分配错误" << std::endl;
    }else{
        first->next = first; //后继节点指向自己
        first->prev = first;
    }
}
```

获取存储的元素个数

```cpp
/**
 * 获取双向循环链表的长度
 * @tparam T
 * @return 链表的长度，即储存的元素个数
 */
template<class T>
int DbLinkList<T>::Length() const {
    int length = 0;
    DbLinkNode<T>* node = first->next;
    while(node!=first){
        node = node->next;
        length++;
    }
    return length;
}
```

判断链表是否为空

```cpp
/**
 * 判断链表是否为空
 * @tparam T
 * @return true为空，false为不空
 */
template<class T>
bool DbLinkList<T>::IsEmpty() const {
    return first->next==first;
}
```

设置头节点

```cpp
/**
 * 设置头节点
 * @tparam T
 * @param ptr
 */
template<class T>
void DbLinkList<T>::setHead(DbLinkNode<T> *ptr) {
    first = ptr;
}
```

在双向链表中以后继方向从头开始寻找值为x的结点地址

```cpp
/**
 * 在双向链表中以后继方向从头开始寻找值为x的结点地址
 * @tparam T
 * @param x 给定的元素值
 * @return 结点地址
 */
template<class T>
DbLinkNode<T> *DbLinkList<T>::Search(const T &x) {
    DbLinkNode<T>* node = first->next;
    while(node!=first){
        if(node->data == x)
            break;
        node = node->next;
    }
    if(node!=first)
        return node;
    else
        return NULL;
}
```

寻找链表序号为i的点

```cpp
/**
 * 寻找链表序号为i的点
 * @tparam T
 * @param i
 * @param d d=0按照前驱方向寻找,d!=0按照后继节点寻找
 * @return
 */
template<class T>
DbLinkNode<T> *DbLinkList<T>::Locate(int i, int d) {
    if(first->next==first||i=0)
        return first;
    DbLinkNode<T> * current;
    if(d==0)
        current = first->prev; //搜索方向
    else
        current = first->next;
    for(int j = 1;j<i;j++){
        if(current == first)
            break;
        else if(d==0)
            current = current->prev;
        else
            current = current->next;
    }
    if(current!=first)
        return current;
    else
        return NULL;
}
```

## 3. 扩展线性表

此部分主要考察以下内容

1. 栈、队列、多维数组、串的基本概念；
2. 栈的顺序存储结构、链式存储结构、基本操作和应用（含递归）；
3. 队列的顺序存储结构、链式存储结构、基本操作和应用（含优先级队列）；
4. 多维数组的存储、稀疏矩阵；
5. 串的存储结构、模式匹配算法（含KMP）；
6. 经典算法应用：贪心、穷举、分治、回溯和动态规划。

### 3.1 栈

#### 3.1.1 栈的定义

==栈(Stack)可定义为只允许在表的末端进行插入和删除的线性表==。允许插入删除的一端叫做栈顶(top),而不允许插入和删除的另一端叫做栈底(bottom)。栈又叫做**先进后出(LIFO,Last In First Out)**。

栈的类定义:

```cpp
/**
 * 栈的类定义
 * @tparam T
 */
template <class T>
class Stack {
  Stack(){}
  virtual void Push(const T& x) = 0; //新元素x进栈
  virtual bool Pop(T& x) = 0; //栈顶元素出栈,由x返回
  virtual bool getTop(T& x)const = 0; //获取栈顶元素
  virtual bool IsEmpty()const = 0; //判断栈是否为空
  virtual bool IsFull()const = 0; //判断是否栈满
  virtual int getSize()const = 0; //计算栈中的元素
};
```

#### 3.1.2 顺序栈

借助数组来实现栈的方式我们称为顺序栈

##### 3.1.2.1 顺序栈的类定义

```cpp
const int SEQSTACK_OVERFLOW_ADD_SIZE = 20;

template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);
    ~SeqStack();
    void Push(const T &x);
    bool Pop(T &x);
    bool getTop(T &x) const;
    bool IsEmpty() const;
    bool IsFull() const;
    int getSize() const;

private:
    T *elements; //存放栈中元素数组
    int top;
    int MaxSize;
    void OverflowStack(); //栈的溢出处理
};
```

##### 3.1.2.2 顺序栈的完整实现

```cpp
/**
 * 构造函数
 * @tparam T
 * @param sz
 */
template<class T>
SeqStack<T>::SeqStack(int sz):top(-1), MaxSize(sz)
{
    elements = new T[MaxSize];
    assert(elements!=NULL);
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
inline SeqStack<T>::~SeqStack()
{
    delete[]elements;
}

/**
 * 新元素进栈
 * @tparam T
 * @param x 进栈元素
 */
template<class T>
inline void SeqStack<T>::Push(const T& x)
{
    if (IsFull()) {
        OverflowStack();
    }
    elements[++top] = x;
}

/**
 * 栈顶元素出栈
 * @tparam T
 * @param x 返回的栈顶元素
 * @return 出栈操作结果
 */
template<class T>
inline bool SeqStack<T>::Pop(T& x)
{
    if (IsEmpty()) {
        std::cerr << "栈为空" << std::endl;
        return false;
    }
    x = elements[top--];
    return true;
}

/**
 * 获取栈顶元素
 * @tparam T
 * @param x 获取到的元素
 * @return 操作结果
 */
template<class T>
inline bool SeqStack<T>::getTop(T& x)const
{
    if (IsEmpty()) {
        std::cerr << "栈为空" << std::endl;
        return false;
    }
    x = elements[top];
    return true;
}

/**
 * 判断是否栈空
 * @tparam T
 * @return
 */
template<class T>
inline bool SeqStack<T>::IsEmpty()const
{
    return top == -1;
}

/**
 * 判断是否栈满
 * @tparam T
 * @return
 */
template<class T>
inline bool SeqStack<T>::IsFull()const
{
    return top == MaxSize - 1;
}

/**
 * 获取栈内元素的大小
 * @tparam T
 * @return
 */
template<class T>
inline int SeqStack<T>::getSize()const
{
    return top + 1;
}

/**
 * 栈的溢出处理
 * @tparam T
 */
template<class T>
void SeqStack<T>::OverflowStack() {
    T *newArray = new T[MaxSize + SEQSTACK_OVERFLOW_ADD_SIZE];
    if(newArray == NULL){
        std::cerr << "空间分配错误" << std::endl;
    }
    for(int i = 0; i < MaxSize;i++){
        newArray[i] = elements[i]; //复制原有栈中数据
    }
    MaxSize = MaxSize + SEQSTACK_OVERFLOW_ADD_SIZE;
    delete []elements;
    elements = newArray;
}
```

#### 3.1.3 链式栈

链式栈的栈顶在链表的表头。因此,新结点的出入和栈顶节点的删除都在链表的表头进行

##### 3.1.3.1 链栈的类定义

```cpp
template <class T>
struct StackNode
{
    T data;
    StackNode<T>* next;
    StackNode(StackNode<T>* ptr = NULL) :next(ptr) {};
    StackNode(const T& x, StackNode<T>* ptr = NULL) :data(x), next(ptr) {};
};

template <class T>
class LinkedStack {
public:
    LinkedStack();
    ~LinkedStack();
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x)const;
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;
    void makeEmpty();

    template<class T>
    friend std::ostream& operator<<(std::ostream& out,LinkedStack<T>&s);

private:
    //头指针不含有效数据
    StackNode<T>* top;
};
```

##### 3.1.3.2 链栈的方法实现

```cpp
template<class T>
inline LinkedStack<T>::LinkedStack()
{
    top = new StackNode<T>();
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
inline LinkedStack<T>::~LinkedStack()
{
    makeEmpty();
}

/**
 * 进栈 头节点插入法
 * @tparam T
 * @param x 进栈元素
 */
template<class T>
inline void LinkedStack<T>::Push(const T& x)
{
    //因为链栈一般不会满,所以我们没必要做判断,直接插入即可
    StackNode<T>* p = new StackNode<T>(x);
    p->next = top->next;
    top->next = p;
}

/**
 * 出栈
 * @tparam T
 * @param x
 * @return
 */
template<class T>
inline bool LinkedStack<T>::Pop(T& x)
{
    if (IsEmpty()) {
        std::cerr << "当前栈为空" << std::endl;
        return false;
    }
    StackNode<T>* p = top->next; //目的是将退栈节点分离出来
    x = p->data;
    top->next = p->next;
    delete p;
    return false;
}

/**
 * 获取栈顶元素
 * @tparam T
 * @param x 栈顶元素
 * @return
 */
template<class T>
inline bool LinkedStack<T>::getTop(T& x) const
{
    if (IsEmpty()) {
        std::cerr << "当前栈为空" << std::endl;
        return false;
    }
    x = top->next->data;
    return true;
}

/**
 * 判断带头节点链表是否为空
 * @tparam T
 * @return 判断结果
 */
template<class T>
inline bool LinkedStack<T>::IsEmpty() const
{
    return top->next == NULL;
}

template<class T>
inline bool LinkedStack<T>::IsFull() const
{
    //链栈从某种意义上来说是不会满的,大小取决于内存的大小
    return false;
}

/**
 * 获取链栈中存储的元素个数
 * @tparam T
 * @return
 */
template<class T>
inline int LinkedStack<T>::getSize() const
{
    if(top==NULL)
        return 0;
    else{
        int count = 0;
        StackNode<T>* node = top->next;
        while(node!=NULL){
            node = node->next;
            count++;
        }
        return count;
    }
}

/**
 * 逐一删除栈中的节点
 * @tparam T
 */
template<class T>
void LinkedStack<T>::makeEmpty(){
    if(top==NULL)
        return;
    StackNode<T>* node;
    while(top!=NULL){
        node = top;
        top = top->next;
        delete top;
    }
}

/**
 * 输出函数重载
 * @tparam T
 * @param out 输出对象
 * @param s 链栈对象
 * @return
 */
template<class T>
std::ostream& operator<<(std::ostream& out,LinkedStack<T>&s) {
    out << "栈中的元素个数为：" << s.getSize() << std::endl;
    if (!s.IsEmpty()) {
        StackNode<T> *node = s.top->next;
        while (node != NULL) {
            out << node->data << std::endl;
            node = node->next;
        }
    }
    return out;
}
```

### 3.2 栈与递归

#### 3.2.1 递归的概念

递归（英语：Recursion），又译为递回，在数学与计算机科学中，是指在函数的定义中使用函数自身的方法。

在以下三种情况下通常使用递归办法:

1. 定义是递归的
  $$n!=\begin{cases}
  1 \qquad n=0 \\
  n(n-1)! \qquad n>0
  \end{cases}$$

    >我们应对此有以下认识:
    >
    >- 对于一个比较复杂的问题，如果我们能够分解成几个相对简单且解法相同的问题，只要解决子问题，原问题就解决了。我们称之为**分治法**
    >- 当分解后的子问题可以解决时，就停止分解。
    >- 递归定义的函数可以用递归过程编程求解。递归的过程直接反映了定义的结构。

2. 数据结构是递归的
   我们以链表的搜索为示例

   ```cpp
    /**
    * 搜索算法的递归实现
    * @tparam T
    * @param first
    * @param x
    * @return
    */
    template<class T>
    LinkNode<T> *LinkList<T>::Search(LinkNode<T> *first, T &x) const {
        if(first==NULL)
            return NULL; //搜索失败
        else if(first->data==x)
            return first; //搜索成功
        else Search(first->next, x); //到下一结点继续搜索
    }
   ```

3. 问题的解法是递归的
   经典汉诺塔

#### 3.2.2 递归过程和递归工作栈

##### 3.2.2.1 递归工作栈

每一层递归调用所需保存的信息构成一个工作记录。通常它包括如下内容:

1. 返回地址:即上一层中本次调用自己的语句的后继语句处。
2. 在本次过程调用时,为与形参结合的实参创建副本。包括传值参数和传值返
回值的副本空间、引用型参数和引用型返回值的地址空间。
3. 本层的局部变量值。

![递归工作栈](https://img-blog.csdnimg.cn/1ea897c35a8b48da9df1983ecb5ccec7.jpg)

##### 3.2.2.2 用栈实现递归过程的非递归算法

### 3.3 队列

#### 3.3.1 队列的概念

==队列(queue)只允许在表的一端进行插入,另一端进行删除==。允许插入的一端叫做队尾(rear),允许删除的一端叫做队头(front)

##### 3.3.1.1 队列的类定义

```cpp
/**
 * 队列的实现
 * @tparam T
 */
template<class T>
class SeqQueue{
public:
    SeqQueue(int size = Default_Max_Size);
    ~SeqQueue();
    bool EnQueue(const T& x);
    bool DeQueue(T &x);
    bool GetFront(T &x);
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;
    template<class T>
    friend ostream& operator<<(ostream& out, SeqQueue<T>& seq);

protected:
    int rear = 0; //队尾
    int front = 0; //队头
    T *elements; //存放元素的数组
    int MaxSize = Default_Max_Size; //队列最大容纳元素个数
};
```

##### 3.3.1.2 队列的一般实现

```cpp
/**
 * 构造函数
 * @tparam T
 * @param size
 */
template<class T>
SeqQueue<T>::SeqQueue(int size) {
    if(size<0){
        std::cerr << "输入的size范围错误"<<std::endl;
    }else{
        elements = new T[size];
        if(elements == NULL){
            std::cerr << "空间分配错误" << std::endl;
        }
    }
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
SeqQueue<T>::~SeqQueue() {
    delete []elements;
}

/**
 * 新元素入队
 * @tparam T
 * @param x 入队元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::EnQueue(const T &x) {
    if(IsFull()){
        return false;
    }else{
        elements[rear++] = x;
        return true;
    }
}

/**
 * 判断队列是否满
 * @tparam T
 * @return
 */
template<class T>
bool SeqQueue<T>::IsFull() const {
    return rear == MaxSize;
}

/**
 * 队头元素出栈
 * @tparam T
 * @param x 出栈元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::DeQueue(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front++];
    return true;
}

template<class T>
bool SeqQueue<T>::IsEmpty() const {
    return front == rear;
}

/**
 * 获取队头元素
 * @tparam T
 * @param x 获取到的元素
 * @return 操作结果
 */
template<class T>
bool SeqQueue<T>::GetFront(T &x) {
    if(IsEmpty())
        return false;
    else
        x = elements[front];
    return true;
}

/**
 * 返回队列里面存储的元素个数
 * @tparam T
 * @return
 */
template<class T>
int SeqQueue<T>::getSize() const {
    return rear - front;
}

/**
 * 正序输出队列中的元素
 * @tparam T
 * @param out
 * @param seq
 * @return
 */
template<class T>
std::ostream &operator<<(std::ostream &out, SeqQueue<T> &seq) {
    for(int i = seq.front; i < seq.rear; i++) {
        out << seq.elements[i];
    }
    return out;
}
```

#### 3.3.2 循环队列

对于上述实现,初始化

```cpp
front = rear = 0
```

队列判空的条件

```cpp
front == rear;
```

队列判满的条件

```cpp
rear == MaxSize;
```

基于这种实现很容易产生假"溢出",因为在队列的前端可能还有空间,因此可以将数组的前端和后端链接起来形成循环链表，因而指针的移动可以改为：

```cpp
front = (front + 1) % maxSize;
rear = (rear + 1) % maxSize;
```

但这也导致了一个问题，倘若元素添加过快或者删除过慢，都会导致队头和队尾指针相同,从而导致无法判断队列是满还是空，因此为了区别队空的条件，我们将判满条件修改为

```cpp
(rear + 1) % MaxSize == front
```

让队尾指针在front的**前一位**就判断队列满，进而区分$front == rear$的队空判断条件,在此情况下队列最多盛放$MaxSize-1$个元素。

##### 3.3.2.1 循环队列的类定义

```cpp
template<class T>
class CircQueue{
public:
    CircQueue(int size);
    ~CircQueue();
    bool EnQueue(const T& x);
    bool DeQueue(T &x);
    bool GetFront(T &x);
    void makeEmpty();
    bool IsEmpty()const;
    bool IsFull()const;
    int getSize()const;

    template<class T>
    friend std::ostream& operator<<(std::ostream& out, CircQueue<T>& circQueue);

protected:
    int front = 0; //队头指针
    int rear = 0; //队尾指针
    int *elements; //元素数组
    int MaxSize; //最大盛放的元素数组
};
```

##### 3.3.2.2 循环队列的具体实现

```cpp
template<class T>
CircQueue<T>::CircQueue(int size):front(0),rear(0),MaxSize(size) {
    elements = new T[MaxSize];
    if(elements == NULL)
        std::cerr << "空间分配错误" <<std::endl;
}

template<class T>
CircQueue<T>::~CircQueue() {
    delete []elements;
}

/**
 * 将元素插入到队尾,否则出错处理
 * @tparam T
 * @param x 进队元素
 * @return 操作结果
 */
template<class T>
bool CircQueue<T>::EnQueue(const T &x) {
    if(IsFull())
        return false;
    elements[rear] = x;
    rear = (rear + 1) % MaxSize;
    return true;
}

/**
 * 若队列不为空则删除队头元素并返回true,否则返回false
 * @tparam T
 * @param x
 * @return
 */
template<class T>
bool CircQueue<T>::DeQueue(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front];
    front = (front + 1) % MaxSize;
    return true;
}

template<class T>
bool CircQueue<T>::GetFront(T &x) {
    if(IsEmpty())
        return false;
    x = elements[front];
    return true;
}

/**
 * 队头队尾指针置零
 * @tparam T
 */
template<class T>
void CircQueue<T>::makeEmpty() {
    front = rear = 0;
}

template<class T>
bool CircQueue<T>::IsEmpty() const {
    return front == rear;
}

template<class T>
bool CircQueue<T>::IsFull() const {
    return (rear + 1) % MaxSize == front;
}

/**
 * 求列表元素个数
 * @tparam T
 * @return
 */
template<class T>
int CircQueue<T>::getSize() const {
    return (rear - front + MaxSize) % MaxSize;
}

template<class T>
std::ostream &operator<<(std::ostream &out, CircQueue <T> &circQueue) {
    for (int i = circQueue.front; i < circQueue.rear; i++)  {
        out << circQueue.elements[i];
    }
    return out;
}
```

## 4. 树与二叉树

此部分主要考察以下内容

1. 树、二叉树和森林的基本概念，树、二叉树和森林的遍历操作，树、森林与二叉树的转换；
2. 完全二叉树与满二叉树的基本概念，二叉树的基本性质；
3. 树和二叉树的存储结构；
4. 二叉链表存储结构的构造、二叉树的前序遍历、中序遍历、后序遍历与按层次遍历，以及在二叉链表基础上各种相关算法的设计与应用（含算术表达式二叉树）；
5. 哈夫曼树和哈夫曼编码的基本概念、实现和应用。

（五）图

1）图的基本概念、名词术语；

2）邻接矩阵、邻接表、邻接多重表、十字链表、边集数组的存储方法；

3）图的深度优先搜索与广度优先搜索的算法过程；

4）最小生成树、最短路径、拓扑排序和关键路径算法的原理与应用求解过程；

5）图的基本应用，比如图的连通性、染色问题等。

（六查找

1）查找的基本概念，平均查找长度的计算等；

2）顺序查找法、折半查找法、索引查找算法；

3）二叉排序树、平衡二叉树的基本概念、建立、插入、删除、查找算法；

1) B-树的基本概念，B-树的查找、插入和删除算法；

2) 散列(Hash)技术基本概念、散列函数的构造，冲突处理的方法和应用。

### 3.1.3 链栈

# 7. 排序

直接插入排序、折半插入排序、希尔排序、简单选择排序、起泡排序、快速排序、堆排序和二路归并排序算法的排序原理、规律、特点和实现

## 7.1 直接插入排序

- 基本思想
  当插入第$i(i>=1)$个元素的时候，前面的$V[0],V[1],...,V[i-1]$个元素已经排好序
- 算法分析
  排序码比较次数(**KCN**)
  $$KCN = \sum_{i=1}^{n-1}i=\frac{n(n-1)}{2}\approx\frac{n^2}{2}$$

  元素移动次数(**RMN**)
  $$RMN = \sum_{i=1}^{n-1}i+2=\frac{(n+4)(n-1)}{2}\approx\frac{n^2}{2}$$

- 代码实现

  ```cpp
  //插入排序
  //@param arr 待排序数组
  //@param len 待排序数组长度
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
  ```

## 7.2 折半插入排序

- 基本思想
  当插入第$i(i>=1)$个元素的时候，前面的$V[0],V[1],...,V[i-1]$个元素已经排好序，然后使用折半查找$V[i]$的插入位置
- 算法分析
  排序码比较次数
  $$KCN = \sum_{i=1}^{n-1}\llcorner log_2i+1 \lrcorner \approx nlog_2n$$
- 算法实现

  ```cpp
  //折半插入排序
  //@param arr 待排序数组
  //@param len 待排序数组长度
  void BinaryinsertionSort(int arr[], int len)
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
  ```

2）计数排序、桶排序和基数排序的原理、规律、特点和实现；

3）各种内部排序算法的比较；

4）排序算法的应用。


（三）扩展线性表

1）栈、队列、多维数组、串的基本概念；

2）栈的顺序存储结构、链式存储结构、基本操作和应用（含递归）；

3）队列的顺序存储结构、链式存储结构、基本操作和应用（含优先级队列）；

4）多维数组的存储、稀疏矩阵；

5）串的存储结构、模式匹配算法（含KMP）；

6）经典算法应用：贪心、穷举、分治、回溯和动态规划。

（四）树与二叉树

1）树、二叉树和森林的基本概念，树、二叉树和森林的遍历操作，树、森林与二叉树的转换；

2）完全二叉树与满二叉树的基本概念，二叉树的基本性质；

3）树和二叉树的存储结构；

4）二叉链表存储结构的构造、二叉树的前序遍历、中序遍历、后序遍历与按层次遍历，以及在二叉链表基础上各种相关算法的设计与应用（含算术表达式二叉树）；

5）哈夫曼树和哈夫曼编码的基本概念、实现和应用。

（五）图

1）图的基本概念、名词术语；

2）邻接矩阵、邻接表、邻接多重表、十字链表、边集数组的存储方法；

3）图的深度优先搜索与广度优先搜索的算法过程；

4）最小生成树、最短路径、拓扑排序和关键路径算法的原理与应用求解过程；

5）图的基本应用，比如图的连通性、染色问题等。

（六）查找

1）查找的基本概念，平均查找长度的计算等；

2）顺序查找法、折半查找法、索引查找算法；

3）二叉排序树、平衡二叉树的基本概念、建立、插入、删除、查找算法；

1) B-树的基本概念，B-树的查找、插入和删除算法；

2) 散列(Hash)技术基本概念、散列函数的构造，冲突处理的方法和应用。

（七）排序

1）直接插入排序、折半插入排序、希尔排序、简单选择排序、起泡排序、快速排序、堆排序和二路归并排序算法的排序原理、规律、特点和实现；

2）计数排序、桶排序和基数排序的原理、规律、特点和实现；

3）各种内部排序算法的比较；

4）排序算法的应用。