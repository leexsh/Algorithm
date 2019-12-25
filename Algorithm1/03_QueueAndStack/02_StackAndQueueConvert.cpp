#include"bits/stdc++.h"
using namespace std;

// 如何仅用队列结构实现栈结构
class MyStack{
public:  
    queue<int> q1;
    queue<int> q2;
    MyStack(){}
    //push
    void push(int num){
        q1.push(num);
    }
    //pop
    int pop(){
        if(q1.empty()){
            cout<<"栈中是空"<<endl;
            return -1;
        }
        //把q1中的元素放到q2中 只留下一个元素
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int num = q1.front();
        // 弹出
        q1.pop();
        // 再把q2中的剩下元素放回到q1中
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
    //top
    int top(){
        if(q1.empty()){
            cout<<"栈是空的"<<endl;
            return -1;
        }
        //把q1中的元素放到q2中 只留下一个元素
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int num = q1.front();
        q2.push(num);
        q1.pop();
        // 再放回去
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
  
};

// 如何仅用栈结构实现队列结构
class MyQueue{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue(){}
    //push到s1中
    void push(int num){
        s1.push(num);
    }
    //pop 返回对头元素
    int pop(){
        //队列为空
        if(s2.empty() && s1.empty()){
            cout<<"队列为空"<<endl;
            return -1;
        }
        //栈2为空 栈1中元素全部进栈2
        else{
            if(s2.empty()){
                while(!s1.empty()){
                    // int num = s1.pop();
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    int top(){
        if(s2.empty() &&s1.empty()){
            cout<<"队列为空"<<endl;
            return -1;
        }
        else
        {
            if(s2.empty()){
                while(!s1.empty()){
                    int num = s1.top();
                    s2.push(num);
                    s1.pop();
                }
            }
        }
        return s2.top();
    }
};
int main(){
    MyQueue ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    cout<<ms.top()<<endl;
    cout<<ms.pop()<<endl;

    cout<<ms.pop()<<endl;
    cout<<ms.pop()<<endl;
    system("pause");
    return 0;
}