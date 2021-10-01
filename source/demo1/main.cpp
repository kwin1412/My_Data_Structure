# include <iostream>
using namespace std;

// elem type
#define ElemType int
#define MAX_SIZE 50

typedef struct 
{
      ElemType data[MAX_SIZE];
      int length;
} SqList;

void ListPrint(SqList L)
{
      for (int i = 0; i < L.length;i++)
      {
            cout << L.data[i] << " ";
      }
      cout << endl;
}

bool ListInsert(SqList &L,int i,ElemType e)
{
      //
      if (i>L.length +1 || i<1)
      {
            cout << "invild pos" << endl;
            return false;
      }
            
      if(i>MAX_SIZE)
      {
            cout << "out max size" << endl;
            return true;
      }

      //位置i后的元素都后移
      for (int j = L.length; j >=i;j--)
            L.data[j] = L.data[j - 1];

      //赋值
      L.data[i - 1] = e;
      return true;
}


int main()
{
      SqList sq;
      sq.length = 0;
      //ListInsert(sq,1,1);
      
      for (int i = 0; i < MAX_SIZE-1;i++)
            ListInsert(sq,i+1,i+1);

      ListPrint(sq);
      printf("build at %s",__TIME__);
      return 0;
}