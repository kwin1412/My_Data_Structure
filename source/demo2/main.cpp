# include <iostream>
#define ElemType int

using namespace std;

/* 链表结构体 */
/*
*LNode 节点
*LinkList 结点指针
*/
typedef struct LNode{
      ElemType data;
      struct LNode *next;
}LNode,*LinkList;

void List_Print(LinkList L)
{
      LinkList p;
      p = L->next;
      if (p== NULL)
      {
            return;
      }
      while (p->next!=NULL)
      {
            cout << p->data << " ";
            p = p->next;
      }
      cout << endl;
      return;
}


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



int main()
{
      /*定义头指针*/
      LinkList Head;
      ElemType numList[] = {1,2,3,4,5,6,7,8,9,10};
      Head=List_HeadInsert(Head);
      List_Print(Head);
      printf("build at %s", __TIME__);
      return 0;
}