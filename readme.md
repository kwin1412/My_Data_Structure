# 数据结构

## 1.线性表

![线性表](images\线性表.png)


### 线性表的基本操作

![线性表基本操作](images\线性表基本操作.png)

### 线性表数组实现



### 线性表链表实现

```C++
/* 链表结构体 */
/*
*LNode 节点
*LinkList 结点指针
*/
typedef struct LNode{
      ElemType data;
      struct LNode *next;
}LNode,*LinkList;

```



#### 单链表

##### 1.头插法建立单链表

每次都是从Head指针后边插入，遍历输出后是相反的输出

```c++
/**
 * @brief 头插法建立单链表
 * 头插法是每次都在头指针后边插入一个节点
 * 
 * @param L 
 * @return LinkList 
 */
LinkList List_HeadInsert(LinkList &L)
{
      LinkList s;
      ElemType x;
      /*创建头节点*/
      L = (LinkList)malloc(sizeof(LNode));
      /*初始化一下头节点*/
      L->next = NULL;

      /* 输入节点值 */
      cin >> x;
      /* 终止条件为999 */
      while(x!=999)
      {
            s = (LinkList)malloc(sizeof(LNode));
            s->data = x;
            s->next = L->next;
            L->next = s;
            cin >> x;
      }

      return L;
}
```

##### 2.尾插法建立单链表

```c++
/**
 * @brief 尾插法，使得插入的数据顺序排列
 * 
 * @param L 
 * @return LinkList 
 */
LinkList List_TailInsert(LinkList &L)
{
      L = (LinkList)malloc(sizeof(LNode));
      L->next = NULL;

      ElemType x;
      cin >> x;

      /* s是新生成的节点，r是当前节点指针 */
      LinkList s,r=L;

      while(x!=999)
      {
            /* 申请一个新的节点，s*/
            s = (LinkList)malloc(sizeof(LNode));
            s->data = x;
            s->next = r->next;
            r->next = s;
            r = s;
            cin >> x;
      }
      //r->next = NULL;
      return L;
}
```



#### 双链表


#### 静态链表



## 2.栈

### 2.1栈的顺序存储结构

### 2.2栈的链式存储结构



## 3.队列

### 3.1队列的顺序存储结构

#### 3.2队列的链式存储结构



## 4.特殊矩阵的压缩存储

