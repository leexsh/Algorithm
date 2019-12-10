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
// set的方法 第一个重复的节点就是有环
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
// 2.如何判断两个无环链表是否相交并找到第一个相交的节点
// 利用集合的方法
ListNode *FindFirstInterNode1(ListNode *head1, ListNode *head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    set<ListNode*> s;
    ListNode *p = head1;
    while (p)
    {
        s.insert(p);
        p = p->next;
    }
    p = head2;
    while (p/* condition */)
    {
        if(s.count(p)){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
ListNode *FindFirstInterNode2(ListNode *head1, ListNode *head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    ListNode *cur1 = head1;
    ListNode *cur2 = head2;
    int count = 0;// head1与head2的长度差值
    // 计算head1 的长度
    while(cur1->next){
        count++;
        cur1 =  cur1->next;
    }
    //计算head2与head1的差值
    while(cur2->next){
        count--;
        cur2 = cur2->next;
    }
    // 最后一个节点不相等 肯定不相交
    if(cur1 != cur2){
        return NULL;
    }
    // cur1指向长的链表
    cur1 = count > 0? head1 : head2;
    cur2 = cur1 == head1 ? head2 :head1;
    count = abs(count);
    // 先走差值
    while(count){
        cur1 = cur1->next;
        count--;
    }
    // 一起走
    while(cur1 != cur2){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}
// 3.如何判断两个有环链表是否相交 并找到第一个相交节点
/*
        两个有环链表相交一共就三种情况：
        1    1      1       1           1                 1  
        1    1      1       1            1   11111111    1
        1    1      1       1               1        1   
        1    1          1                    111111111   
                        1
        1.不相交        2.相交后 一起入环       3.一起入环
*/
ListNode *getLoopInterNode(ListNode *head1, ListNode *head2){
    	if (head1 == NULL || head2 == NULL) {
			return NULL;
		}
        // head1 和 head2 的第一个入环节点
		ListNode* loop1 = isLoop2(head1);
		ListNode* loop2 = isLoop2(head2);
        // head1 和 head2 的入环节点为空 也就是没有环 无环链表相交的问题 求第一个入环节点 1.不相交
		if (loop1 == NULL && loop2 == NULL) {
			return FindFirstInterNode2(head1, head2);
		}
        // 两个有环链表相交的问题 2和3
		if (loop1 != NULL && loop2 != NULL) {
			return bothLoop(head1, loop1, head2, loop2);
		}
		return NULL;
}
// 两个有环链表相交的问题
ListNode* bothLoop(ListNode *head1,ListNode *loop1, ListNode *head2,ListNode *loop2){
    ListNode *cur1 = NULL;
    ListNode *cur2 = NULL;
    // 入环节点相同
    if(loop1 == loop2){
        cur1 = head1;
        cur2 = head2;
        int count = 0;// head1与head2的长度差值
        // 计算head1 的长度
        while(cur1->next){
            count++;
            cur1 =  cur1->next;
        }
        //计算head2与head1的差值
        while(cur2->next){
            count--;
            cur2 = cur2->next;
        }
        // 最后一个节点不相等 肯定不相交
        if(cur1 != cur2){
            return NULL;
        }
        // cur1指向长的链表
        cur1 = count > 0? head1 : head2;
        cur2 = cur1 == head1 ? head2 :head1;
        count = abs(count);
        // 先走差值
        while(count){
            cur1 = cur1->next;
            count--;
        }
        // 一起走
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }else{
        // 入环节点不同
        cur1 = loop1->next;
			while (cur1 != loop1) {
				if (cur1 == loop2) {
					return loop1;
				}
				cur1 = cur1->next;
			}
			return NULL;
    }
}
int main(){
    test01();
    system("pause");
    return 0;
}