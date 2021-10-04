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
 * @param pos 从0开始
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

/**
 * @brief 按值查找节点
 * 
 * @param L 
 * @param e 
 * @return LinkList 
 */
LinkList LocateElem(LinkList &L,ElemType e)
{
      LinkList p;
      p = L->next;
      while(p!=NULL)
      {
            if(p->data==e)
                  return p;
            p = p->next;
      }
      return NULL;
}

/**
 * @brief 在节点pos后边插入e
 * 
 * @param L 
 * @param pos 0 base
 * @param e 
 * @return true 
 * @return false 
 */
bool List_BackInsert(LinkList &L,int pos,ElemType e)
{
      LinkList p;
      p = GetElem(L,pos);
      if(p== NULL)
            return false;

      LinkList s;
      s = (LinkList)malloc(sizeof(LNode));
      s->data = e;
      s->next = p->next;
      p->next = s;
      return true;
}

/**
 * @brief 在节点pos前边插入e
 * 
 * @param L 
 * @param pos 0 base
 * @param e 
 * @return true 
 * @return false 
 */
bool List_FrontInsert(LinkList &L,int pos,ElemType e)
{
      LinkList p;
      p = GetElem(L,pos-1);
      if(p== NULL)
            return false;

      LinkList s;
      s = (LinkList)malloc(sizeof(LNode));
      s->data = e;
      s->next = p->next;
      p->next = s;
      return true;
}

/**
 * @brief 找到pos的位置，把数值放在e中，并删除
 * 
 * @param L 
 * @param pos 
 * @param e 
 * @return true 
 * @return false 
 */
bool List_Delete(LinkList &L,int pos,ElemType &e)
{
      LinkList p;
      LinkList q;
      if(pos == 0)
            p = L;
      else
      {
            if((p = GetElem(L, pos-1))==NULL)
            {
                  return false;
            }
      }
      q = p->next;
      p->next = p->next->next;

      free(q);
      return true;
}


int List_GetLength(LinkList &L)
{
      int count = 0;
      LinkList p;
      p = L->next;
      while(p!=NULL)
      {
            count++;
            p = p->next;
      }
      return count;
}

int main()
{
      /*定义头指针*/
      LinkList Head;

      //Head=List_HeadInsert(Head);
      Head=List_TailInsert(Head);

      cout << "input linklist:" << endl;
      List_Print(Head);

      LinkList r;
      if( (r=GetElem(Head,3)) !=NULL)
      {
            cout << "input linklist pos=3 data=:" << endl;
            cout << r->data << endl;
      }

      if( (r=LocateElem(Head,1)) !=NULL)
      {
            cout << "input linklist Elem=1 pos=:" << endl;
            cout << r->data << endl;
      }

      bool a;
      if( (a=List_BackInsert(Head,3,0)) !=false)
      {
            cout << "List_BackInsert Elem=0 pos=3:" << endl;
            List_Print(Head);
      }

      if( (a=List_FrontInsert(Head,0,-1)) !=false)
      {
            cout << "List_FrontInsert Elem=-1 pos=0:" << endl;
            List_Print(Head);
      }

      ElemType e;
      if( (a=List_Delete(Head,0,e)) !=false)
      {
            cout << "List_Delete pos=0:" << endl;
            cout << e << endl;
            List_Print(Head);
      }

      cout << List_GetLength(Head) << endl;

      printf("build at %s", __TIME__);
      return 0;
}