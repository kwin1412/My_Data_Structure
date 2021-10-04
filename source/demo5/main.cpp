/**
 * @file main.cpp
 * @author kwin1412 (you@domain.com)
 * @brief 链表栈的相关操作
 * @version 0.1
 * @date 2021-10-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#define ElemType int

using namespace std;

/**
 * @brief 链表定义，链表栈就是普通的单链表
 * 
 */
typedef struct LNode
{
      ElemType data;
      struct LNode *next;

} LNode,* LinkStack;

/**
 * @brief 入栈操作
 * 入栈的话就是头插法
 * @param S 
 * @param e 
 * @return true 
 * @return false 
 */
bool Push( LinkStack &S,ElemType e)
{
      LinkStack p,sp;
      p = S;
      sp = (LinkStack)malloc(sizeof(LNode));
      sp->data = e;
      sp->next = p->next;
      p->next = sp;
      
      return true;
}


/**
 * @brief 出栈
 * 
 * 
 * @param S 
 * @param e 
 * @return true 
 * @return false 
 */
bool Pop(LinkStack &S,ElemType &e)
{
      LinkStack p, sp;
      p = S;

      if(p->next==NULL)
            return false;

      e = p->next->data;
      sp = p->next;
      p->next = p->next->next;
      free(sp);
      return true;
}

int main()
{
      LinkStack S;
      S = (LinkStack)malloc(sizeof(LNode));
      S->next = NULL;

      for (int i = 0; i < 10;i++)
      {
            Push(S, i);
            cout << i << " ";
      }
      cout << endl;


      ElemType e;
      for (int i = 0; i < 10;i++)
      {
            Pop(S, e);
            cout << e << " ";
      }
      cout << endl;

      cout << "build at " << __TIME__ << endl;
      return 0;
}



