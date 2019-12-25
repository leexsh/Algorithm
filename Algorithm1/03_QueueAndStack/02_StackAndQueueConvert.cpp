#include"bits/stdc++.h"
using namespace std;

// ��ν��ö��нṹʵ��ջ�ṹ
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
            cout<<"ջ���ǿ�"<<endl;
            return -1;
        }
        //��q1�е�Ԫ�طŵ�q2�� ֻ����һ��Ԫ��
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int num = q1.front();
        // ����
        q1.pop();
        // �ٰ�q2�е�ʣ��Ԫ�طŻص�q1��
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
    //top
    int top(){
        if(q1.empty()){
            cout<<"ջ�ǿյ�"<<endl;
            return -1;
        }
        //��q1�е�Ԫ�طŵ�q2�� ֻ����һ��Ԫ��
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int num = q1.front();
        q2.push(num);
        q1.pop();
        // �ٷŻ�ȥ
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return num;
    }
  
};

// ��ν���ջ�ṹʵ�ֶ��нṹ
class MyQueue{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue(){}
    //push��s1��
    void push(int num){
        s1.push(num);
    }
    //pop ���ض�ͷԪ��
    int pop(){
        //����Ϊ��
        if(s2.empty() && s1.empty()){
            cout<<"����Ϊ��"<<endl;
            return -1;
        }
        //ջ2Ϊ�� ջ1��Ԫ��ȫ����ջ2
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
            cout<<"����Ϊ��"<<endl;
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