/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 双链表的相关操作
 * @version 0.1
 * @date 2021-10-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <iostream>
#define ElemType int

using namespace std;
typedef struct DNode
{
      ElemType data;
      struct DNode *prior, *next;

} DNode, *DLinkList;

/**
 * @brief 双向链表顺序输出
 * 
 * @param L 
 */
void DLink_Print(DLinkList L)
{
      DLinkList p;
      p = L->next;
      while(p!=NULL)
      {
            cout << p->data << " ";
            p = p->next;
      }
      cout << endl;
}

/**
 * @brief 后插入创建双链表
 * 
 * @param L 
 * @param e 
 * @return true 
 * @return false 
 */
bool DLink_Insert(DLinkList& L,ElemType e)
{
      DLinkList p;
      p = L;

      while(p->next!=NULL)
      {
            p = p->next;
      }

      DLinkList s;
      s = (DLinkList)malloc(sizeof(DNode));

      s ->data = e;
      s->next = p->next;
      p->next = s;
      s->prior = p;

      
      return true;
}

/**
 * @brief Get the Tail D Node object
 * 
 * @param L 
 * @return DLinkList 
 */
DLinkList GetTailDNode(DLinkList& L)
{
      DLinkList p;
      p = L->next;

      while(p->next!=NULL)
      {
            p = p->next;
      }
      return p;
}

/**
 * @brief 双链表倒叙输出
 * 
 * @param L 
 */
void DLink_ReversePrint(DLinkList& L)
{
      DLinkList Tail;
      Tail = GetTailDNode(L);
      while(Tail->prior!=NULL)
      {
            cout << Tail->data << " ";
            Tail = Tail->prior;
      }
      cout << endl;
}


/*头尾缝合生成循环链表*/
/**
 * @brief 头尾缝合生成循环链表
 * 
 * @param L 
 * @return true 
 * @return false 
 */
DLinkList DLink_Suture(DLinkList& L)
{
      DLinkList Head, Tail;
      Head = L;
      Tail = GetTailDNode(L);

      /*缝合*/
      Tail->next = Head;
      Head->prior = Tail;

      return Head;
}

/*仅作验证用，写法简单，但效率很低，不要模仿*/
DLinkList GetCycleDLinkPosPionter(DLinkList& L,int pos)
{
      DLinkList p;
      p = L->next;
      for (int i = 0; i < pos;i++)
      {
            p = p->next;
      }
      return p;
}
/*仅作验证用，写法简单，但效率很低，不要模仿*/
void DLink_CyclePrint(DLinkList& L,int times)
{
      DLinkList p;
      for (int i = 0; i < times;i++)
      {
           p= GetCycleDLinkPosPionter(L,i);
           cout << p->data << " ";
      }
      cout << endl;
}

int main()
{
      cout << "build at " << __TIME__ << endl;
      DLinkList Head;
      /*创建头节点*/
      Head = (DLinkList)malloc(sizeof(DNode));
      Head->next = NULL;
      Head->prior = NULL;

      for (int i = 0; i < 10;i++)
      {
            DLink_Insert(Head,i);
      }

      DLink_Print(Head);
      DLink_ReversePrint(Head);

      DLink_Suture(Head);
      DLink_CyclePrint(Head,60);
      cout << "build at " << __TIME__ << endl;
      return 0;
}