#include"bits/stdc++.h"
using namespace std;
/**
判断一个链表是否为回文结构
    【题目】 给定一个链表的头节点head，请判断该链表是否为回文结构。 例如： 1->2->1，返回true。 1->2->2->1，返回true。
    15->6->15，返回true。 1->2->3，返回false。   
    进阶： 如果链表长度为N，时间复杂度达到O(N)，额外空间复杂度达到O(1)
*/
class List{
public:
    List(int v) : val(v), next(NULL){}
public:
    int val;
    List *next;
};
bool isHuiWen1(List *head){
    if(head == NULL)
        return false;
    stack<List*> s;
    List *p = head;
    while(p){
        s.push(p);
        p = p->next;
    }
    while(head){
        List *temp = s.top();
        s.pop();
        if(head->val != temp->val){
            return false;
        }
        head = head->next;
    }
    return true;
}
bool isHuiWen2(List *head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    List *p1 = head;// 慢指针
    List *p2 = head;// 快指针
    while(p2->next && p2->next->next){
        // 慢指针一次走一步 快指针一次走两步 如果链表是奇数个 慢指针走到中点位置 如果是偶数个走到中点的前一个位置
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1->next;//fast 指向slow的下一个节点
    p1->next = NULL;//断开左边的链表
    List *p3 = NULL;
    while(p2->next){ //逆序后半部分链表
        p3 = p2->next;//p3指向要逆序的下一个节点
        p2->next = p1;//连接
        p1 = p2;//移动
        p2 = p3;//移动
    }
    p3 = p1;//保存右边逆序链表的头部分 一会还原链表要用
    p2 = head;
    bool res = true;
    //判断是否回文
    while(p2 && p1){
        if(p2->val != p1->val){
            res = false;
            break;
        }
        p2 = p2->next;
        p1 = p1->next;
    }
    //逆序回去
    p1 = p3->next;
    p3->next = NULL;
    while(p1){
        p2 = p1->next;
        p1->next = p3;
        p3 = p1;
        p1 = p2;
    }
    return res;
}
void test01(){
    List *p = new List(1);  
    List *p1 = new List(2);
    p->next = p1;
    List *p2 = new List(2);
    p->next->next = p2;
    List *p3 = new List(1);
    p->next->next->next = p3;
    bool f = isHuiWen2(p);
    if(f){
        cout<<"is HuiWen"<<endl;
    }
    else
    {
        cout<<"not HuiWen"<<endl;
    }
    
    // cout<<f<<endl;
}
int main(){
    test01();
    system("pause");
    return 0;
}