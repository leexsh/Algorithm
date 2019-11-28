#include"bits/stdc++.h"
using namespace std;
// 用数组结构实现大小固定的队列和栈

//队列
class MyQueue{
public: 
    // 默认大小是10
    MyQueue():size(0), front(0), rear(0), length(10){
        arr = new int[10];
    }
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
            cout<<"队满"<<endl;
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
    int *arr;//数组队列
    int size;//元素个数
    int front;//队头
    int rear;//队尾
    int length;
};

class MyStack{
public:
    MyStack(){
        arr = new int[10];
        top = 0;
        size = 10;
    }
    MyStack(int len){
        arr = new int[len];
        top = 0;
        size = len;
    }
    // pop
    int pop(){
        if(top<0)
            return -1;
        return arr[top--];
    }
    // push
    void push(int num){
        if(top + 1 > size)
        return;
        arr[top++] = num;
    }
    // top
    int getTop(){
        return arr[top];
    }
    // isEmpty
    ~MyStack(){
        delete []arr;
        arr = NULL;
    }
public:
    int *arr;
    int top;
    int size;

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