#include"bits/stdc++.h"
using namespace std;
/*
    发现链表中的第一个相交的节点
    两个单链表相交的一系列问题
    【题目】 在本题中，单链表可能有环，也可能无环。给定两个单链表的头节点 head1和head2，这两个链表可能相交，也可能不相交。
    请实现一个函数， 如果两个链表相交，请返回相交的第一个节点；如果不相交，返回null 即可。 
    要求：如果链表1的长度为N，链表2的长度为M，时间复杂度请达到 O(N+M)，额外空间复杂度请达到O(1)。
*/
class ListNode{
public:
    ListNode(int v) : val(v), next(NULL){}
public:
    int val;
    ListNode *next;

};
// 这个题可以拆分为三个题目
// 1.如何判断单链表是否有环并找到第一个入环节点
//set的方法 第一个重复的节点就是有环
ListNode *isLoop1(ListNode *head){
    if(head == NULL){
        return NULL;
    }
    set<ListNode*>s;
    ListNode *p = head;
    while(p){
        s.insert(p);
        if(s.count(p)){
            return p;    
        }
        p = p->next;
    }
    return NULL;
}
//快慢指针的方法 相遇了就是有环 相遇以后快指针从头走 相遇节点就是入环节点
ListNode *isLoop2(ListNode *head){
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != slow){
        if(fast->next == NULL || fast->next->next == NULL){
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
void test01(){
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = p;
    ListNode *pp = isLoop2(p);
    cout<<pp->val<<endl;
}
// 2.如何判断两个链表是否相交并找到第一个相交的节点


// 3.如何判断两个有环链表是否相交 并找到第一个相交节点


int main(){
    test01();
    system("pause");
    return 0;
}