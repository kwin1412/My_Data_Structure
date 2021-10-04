#include <iostream>
#define ElemType int

using namespace std;

#define MAXSIZE 50
//p92

/**
 * @brief 队列
 * 队列像排队一样，排在队尾，从队头出队
 * 初始front = rear =0
 * Q.front=(Q.front+1)%MAXSIZE
 * Q.rear=(Q.rear+1)%MAXSIZE
 * 长度：(Q.rear-Q.front+MAXSIZE)%MAXSIZE
 * 队空：Q.front == Q.rear
 * 队满：(Q.rear+1)%MAXSIZE == Q.front 长度=MAXSIZE-1
 * 
 */
typedef struct queue
{
      ElemType data[MAXSIZE];
      int front, rear;
}SqQueue;


bool QueueEmpty(SqQueue Q)
{
      if(Q.front==Q.rear)
            return true;
      else
            return false;
}

/*入队*/
/**
 * @brief 入队
 * 
 * @param Q 
 * @param e 
 * @return true 
 * @return false 
 */
bool EnQueue(SqQueue &Q,ElemType e)
{
      if((Q.rear+1)%MAXSIZE == Q.front)
            return false;
      Q.data[Q.rear] = e;
      //cout << Q.data[Q.rear] << " ";
      Q.rear = (Q.rear + 1) % MAXSIZE;
      return true;
}

/**
 * @brief 出队
 * 
 * @param Q 
 * @param e 
 * @return true 
 * @return false 
 */
bool DeQueue(SqQueue &Q,ElemType &e)
{
      if(Q.rear == Q.front)
            return false;

      e = Q.data[Q.front];
      Q.front = (Q.front+1) % MAXSIZE;
      return true;
}     

int main()
{
      SqQueue Q;
      Q.front = 0;
      Q.rear = 0;
      cout << "enter queue:";
      for (int i = 0; i < 10;i++)
      {
            EnQueue(Q,i);
            cout << i << " ";
      }
      cout << endl;

      ElemType e;
      cout << "delete queue:";
      for (int i = 0; i < 10;i++)
      {
            DeQueue(Q,e);
            cout << e << " ";
      }
      cout << endl;


      cout << "build at " << __TIME__ << endl;
      return 0;
}