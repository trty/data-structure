#include "iostream"
using namespace std;
typedef char DataType;
const int maxsize = 6;
//顺序存储结构实现队列
class Queue_1
{
    int flag;
    DataType data[maxsize];

public:
    Queue_1()
    {
        flag = 0;
    };
    void EnQueue(DataType d)
    {
        if (flag == maxsize - 1)
        {
            cout << "队列已满!" << endl;
        }
        else
        {
            data[flag++] = d;
        }
    };
    DataType DeQueue()
    {
        if (flag == 0)
        {
            cout << "队列为空!" << endl;
            exit(1);
        }
        else
        {
            DataType d = data[0];
            for (int i = 0; i < flag - 1; i++)
            {
                data[i] = data[i + 1];
            }
            return d;
        }
    };
    bool QueueEmpty()
    {
        return flag == 0 ? 1 : 0;
    };
    DataType GetFront()
    {
        if (flag == 0)
        {
            cout << "队列为空" << endl;
            exit(1);
        }
        else
        {
            return data[0];
        }
    };
    void clear()
    {
        flag = 0;
    };
    bool ifFull()
    {
        return flag == maxsize - 1 ? 1 : 0;
    };
};
//顺序存储结构实现循环队列
class Queue_2
{
    int front, rear;
    DataType data[maxsize];

public:
    Queue_2()
    {
        front = rear = 0;
    };
    void EnQueue(DataType d)
    {
        if ((rear + 1) % maxsize == front)
        {
            cout << "队列已满!" << endl;
        }
        else
        {
            data[rear] = d;
            rear = (rear + 1) % maxsize;
        }
    };
    DataType DeQueue()
    {
        if (front == rear)
        {
            cout << "队列为空!" << endl;
            exit(0);
        }
        else
        {
            DataType d = data[front];
            front = (front + 1) % maxsize;
            return d;
        }
    };
    bool QueueEmpty()
    {
        return rear == front ? 1 : 0;
    };
    DataType GetFront()
    {
        if (front == rear)
        {
            cout << "队列为空!" << endl;
            exit(0);
        }
        else
        {
            return data[front];
        }
    };
    void clearQueue()
    {
        rear = front;
    };
    bool ifFull()
    {
        return (rear + 1) % maxsize == front ? 1 : 0;
    };
};
int main()
{
    Queue_1 q;
    cout<<"入队:";
    for (int i=0;q.ifFull();i++)
    {
        cout<<'q'+i<<" ";
        q.EnQueue('q'+i);
    }
    cout<<"\n出队:";
    while(!q.QueueEmpty()){
        cout<< q.DeQueue()<<" ";
    }
    cout<<endl;
    return 0;
}