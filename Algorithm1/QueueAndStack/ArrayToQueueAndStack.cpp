#include"bits/stdc++.h"
using namespace std;
// ������ṹʵ�ִ�С�̶��Ķ��к�ջ

//����
class MyQueue{
public:
    MyQueue():arr(NULL), size(0), front(0), rear(0){}
    MyQueue(int len){
        arr = new int[len];
        size = 0;
        front = 0;
        rear = 0;
        length = len;
    }
    ~MyQueue(){
        delete []arr;
        arr = NULL;
    }
    // push
    void push(int num){
        if(size == length){
            cout<<"����"<<endl;
            return;
        }
        size++;
        arr[rear] = num;
        rear = rear == length ? 0 : rear + 1;
    }
    // pop
    int pop(){
        if(size == 0){
            return -1;
        }
        int temp = front;
        --size;
        front = front == length ? 0 : front + 1;
        return arr[temp];
    }
    // peek
    int peek(){
        if(size == 0)
        {
            return -1;
        }
        return arr[front];
    }
public:
    int *arr;//�������
    int size;//Ԫ�ظ���
    int front;//��ͷ
    int rear;//��β
    int length;
};

class MyStack{
public:
public:

};
int main(){
    MyQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<" ";
    cout<<q.peek()<<endl;
    cout<<q.pop()<<" ";
   
    system("pause");
    return 0;
}