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

      while (p!=NULL)
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

/**
 * @brief Get the Elem object
 * 
 * @param L 
 * @param pos 
 * @return LinkList 
 */
LinkList GetElem(LinkList &L,int pos)
{
      LinkList r=L;
      ElemType x;
      for (int i = 0; i <=pos;i++)
      {
            if(r==NULL)
                  return NULL;
            r = r->next;
      }
      return r;
}

LinkList LocateElem(LinkList &L)
{

}

int main()
{
      /*定义头指针*/
      LinkList Head;

      //Head=List_HeadInsert(Head);
      Head=List_TailInsert(Head);

      List_Print(Head);

      LinkList r;
      if( (r=GetElem(Head,3)) !=NULL)
      {
            cout << r->data << endl;
      }

      printf("build at %s", __TIME__);
      return 0;
}