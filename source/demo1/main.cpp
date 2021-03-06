# include <iostream>
#include <ctime>

using namespace std;


// elem type
#define ElemType int
#define MAX_SIZE 20

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

/**
 * @brief   顺序表的插入操作
 * @param L SqList的顺序表
 * @param i SqList的顺序表插入位置
 * @param e SqList的顺序表插入元素
 * @return  true 插入成功
 * @return  false 
 */
bool ListInsert(SqList &L,int i,ElemType e)
{
      /* 位置检查 */
      /*
      *检查是不是超过现有长度+1
      *检查是不是位置0
      *检查是不是超过最大长度
      */
      if (i>L.length +1 || i<1 || i>MAX_SIZE)
      {
            cout << "invild pos" << endl;
            return false;
      }

      //位置i后的元素都后移
      for (int j = L.length; j >=i;j--)
            L.data[j] = L.data[j - 1];

      //赋值
      L.data[i - 1] = e;
      L.length++;
      return true;
}

/**
 * @brief 顺序表删除操作
 * 
 * @param L 
 * @param pos 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListDelete(SqList &L,int pos,ElemType &e)
{
      if(pos < 1 || pos>L.length)
      {
            cout << "invaild pos";
            return false;
      }

      /*删除的元素放到e中*/
      e = L.data[pos - 1];
      
      /*将后边的元素往前推*/
      for (int i = pos; i < L.length;i++)
      {
            L.data[i-1] = L.data[i];
           
      } 

      L.length--;
      return true;
}

/**
 * @brief 查找某一个元素
 * 
 * @param L 
 * @param e 
 * @return int 0查找失败，非0查找成功
 */
int LocateElem(SqList &L,int e)
{
      for (int i = 0; i < L.length;i++)
            if(L.data[i]==e)
                  return i + 1;
      return 0;
}

int main()
{
      SqList sq;
      sq.length = 0;
      /*使用插入初始化顺序表*/
      for (int i = 0; i < MAX_SIZE;i++)
            ListInsert(sq,i+1,i+1);

      ListPrint(sq);

      /* 删除顺序表 */
      for (int i = 1; i <= MAX_SIZE/2;i++)
      {
            ElemType e;
            ListDelete(sq,i,e);
            //cout << e << " ";
      }

      ListPrint(sq);

      /* 查找顺序表 */
      int rand_num;
      srand(time(0));
      rand_num = rand() % MAX_SIZE + 1;

      if(LocateElem(sq,rand_num)!=0)
            cout << "locate num = " << rand_num << " 's position is " << LocateElem(sq, rand_num) << endl;
      else
            cout << "locate num = " << rand_num << " no found " <<endl;
      printf("build at %s", __TIME__);
      return 0;
}