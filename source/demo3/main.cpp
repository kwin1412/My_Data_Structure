#include <iostream>
#define ElemType int

using namespace std;
typedef struct DNode
{
      ElemType data;
      struct DNode *prior, *next;

} DNode, *DLinkList;


void DLink_Print(DLinkList L)
{
      DLinkList p;
      p = L->next;
      while(p!=NULL)
      {
            cout << p->data << " ";
            p = p->next;
      }

}

/**插入*/
bool DLink_Insert(DLinkList& L,int pos,ElemType e)
{
      DLinkList p;
      p = L;
      cout << __FUNCTION__ << endl;
      for (int i = 0; i < pos;i++)
      {
            p = p->next;
            cout << "p next" << endl;
      }
      DLinkList s;
      s = (DLinkList)malloc(sizeof(DNode));
      s ->data = e;

      s->next = p->next;
      p->prior = s;

      p->next ->prior= s;
      s->next = p;
      return true;
}

int main()
{
      DLinkList Head;
      ElemType num[] = {1,2,3,4,5,6,7,8,9,10};
      for (int i=0;i<10;i++)
            DLink_Insert(Head, i, i);

      DLink_Print(Head);
      cout << "build at " << __TIME__ << endl;
      return 0;
}