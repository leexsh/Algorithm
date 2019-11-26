#include"bits/stdc++.h"
using namespace std;
// 用数组结构实现大小固定的队列和栈

//队列
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
        return arr[front];
    }
public:
    int *arr;//数组队列
    int size;//元素个数
    int front;//队头
    int rear;//队尾
    int length;
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
    cout<<q.peek()<<endl;
    cout<<q.pop()<<" ";
    cout<<q.peek()<<endl;
    cout<<q.pop()<<" ";
    cout<<q.peek()<<endl;
    // cout<<q.pop()<<" "<<q.peek()<<" "<<q.pop()<<endl;
    // int arr = new int[3];
    // cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    system("pause");
    return 0;
}