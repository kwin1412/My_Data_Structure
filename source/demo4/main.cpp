/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 数组栈实现
 * @version 0.1
 * @date 2021-10-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#define ElemType int

using namespace std;

#define MAXSIZE 50

typedef struct 
{
      ElemType data[MAXSIZE];
      int top;
}SqStack;

/*
* 初始化，栈顶指针S.top=-1,
* 栈顶元素S.data[S.top]
* 压栈时，指针先+1，再复制
* 出栈时，先赋值，再指针-1
* 条件：栈空 S.top = -1
*     栈满 S.top = MAXSIZE-1,
*     栈长 S.top + 1
*/

/**
 * @brief 初始化栈
 * 栈指针=-1
 * 
 * @param S 
 */
void InitStack(SqStack &S)
{
      S.top = -1;
}

/**
 * @brief 判断stack 是否为空
 * 
 * @param S 
 * @return true 
 * @return false 
 */
bool StackEmpty(SqStack S)
{
      if(S.top==-1)
            return true;
      else
            return false;
}

/**
 * @brief 压栈，将元素放到栈里
 * 
 * @param S 
 * @param e 
 * @return true 
 * @return false 
 */
bool Push(SqStack &S,ElemType e)
{
      if(S.top==MAXSIZE-1)
            return false;
      S.top++;
      S.data[S.top] = e;
      return true;
}

/**
 * @brief 出栈，输出元素
 * 
 * @param S 
 * @param e 
 * @return true 
 * @return false 
 */
bool Pop(SqStack &S,ElemType &e)
{
      if(StackEmpty(S)==true)
            return false;
      e=S.data[S.top];
      S.top--;
      return true;
}

int main()
{
      SqStack S;

      cout << "Push is :";
      for (int i = 0; i < 10;i++)
      {
            Push(S, i);
            cout << i << " ";
      }
      cout << endl;

      ElemType e;
      cout << "Pop is :";
      for (int i = 0; i < 10;i++)
      {
            Pop(S, e);
            cout << e << " ";
      }
      cout << endl;

      cout << "build at " << __TIME__ << endl;
      return 0;
}