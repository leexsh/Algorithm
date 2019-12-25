#include"bits/stdc++.h"
using namespace std;
/*
反转单向和双向链表
【题目】 分别实现反转单向链表和反转双向链表的函数。
【要求】 如果链表长度为N，时间复杂度要求为O(N)，额外空间
复杂度要求为O(1)
*/
//单向链表
class List{
public:
    List(int x):val(x), next(NULL){}
public:
    int val;
    List *next;
};
//双向链表
class DouList{
public:
    DouList(int x):val(x), pre(NULL), next(NULL){}
public:
    int val;
    DouList *pre;
    DouList *next;
};
//翻转单向链表(非递归)
List* reverseList1(List *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // 表头
    List *pre = new List(-1);
    //指向连接的下一个节点
    List *next = NULL;
    while(head->next){
        next = head->next;
        // 头插法
        head->next = pre->next;
        pre->next = head;
        // head继续到原链表的头部
        head = next;
    }
    // 头插法插入最后一个节点
    head->next = pre->next;
    pre->next = head;
    return pre->next;
}
DouList *reverseDouList(DouList *node){
    if(node == NULL || node->next == NULL){
        return node;
    }
    DouList *pHead = new DouList(-1);
    DouList *pNext;
    while(node->next){
        pNext = node->next;
        node->next = pHead->next;
        node->pre = pHead;
        node->next->pre = node;
        pHead->next = node;
        node = pNext;
    }
    node->next = pHead->next;
    node->next->pre = node;
    node->pre = pHead;
    pHead->next = node;

    return pHead->next;
}
//递归打印单向链表
List *ResverList2(List *node){
    if (node == NULL || node->next == NULL) return node;
    List* p = ResverList2(node->next);
    node->next->next = node;
    node->next = NULL;
    return p;

}
void print(List *l){
    while(l){
        cout<<l->val<<" ";
        l = l->next;
    }
}
void test01(){
    List *p = new List(1);  
    List *p1 = new List(2);
    p->next = p1;
    List *p2 = new List(3);
    p->next->next = p2;
    List *p3 = new List(4);
    p->next->next->next = p3;
    List* pv = reverseList1(p);
    print(pv);
}
int main(){
    test01();
    system("pause");
    return 0;
}