#include"bits/stdc++.h"
using namespace std;
/**
实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返 回栈中最小元素的操作。 
【要求】 
    1．pop、push、getMin操作的时间复杂度都是O(1)。 
    2．设计的栈类型可以使用现成的栈结构
*/
class MinStack {
public:
    stack<int> s;//数据栈
    stack<int> min;//辅助栈
    /** initialize your data structure here. */
    MinStack() {
        
    }
    //x 比top()大 就再入个top 否则入x
    void push(int x) {
        s.push(x);
        if(min.empty()||x<=min.top())
        {
            min.push(x);
        }
        else{
            min.push(min.top());
        }
    }
    
    //一起出
    void pop() {
        min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    int getMin() {
        return min.top();
    }
};


// 法2 利用一个栈 将数据和最小值都入到一个栈中，数据在当前最小值的下面
class MinStack2 {
public:
    stack<int> s;
    
    MinStack2() {}
    
    void push(int x) 
    {
       if(s.empty())
       {
           s.push(x);
           s.push(x);
       }
       else
       {
           int top = s.top();
           s.push(x);
           if(top > x)
           {
               s.push(x);
           }
           else
           {
               s.push(top);
           }
       }
    }
    
    void pop() {
       s.pop();
       s.pop();
    }
    
    int top() {
      int min = s.top();
      s.pop();
      int top = s.top();
      s.push(min);
      return top;
    }
    
    int getMin() {
        return s.top();
    }
};
int main(){

    system("pause");
    return 0;
}