#include"bits/stdc++.h"
using namespace std;
/*
    复制含有随机指针节点的链表
    【题目】 一种特殊的链表节点类描述如下：
    public class Node { 
        public int value; 
        public Node next; 
        public Node rand;
        public Node(int data) { 
            this.value = data; 
        }
    }
    Node类中的value是节点值，next指针和正常单链表中next指针的意义一 样，都指向下一个节点，
    rand指针是Node类中新增的指针，这个指针可能指向链表中的任意一个节点，也可能指向null。 给定一个由
    Node节点类型组成的无环单链表的头节点head，请实现一个 函数完成这个链表中所有结构的复制，并返回复制的新链表的头节点。 
    进阶：不使用额外的数据结构，只用有限几个变量，且在时间复杂度为 O(N)内完成原问题要实现的函数。
*/
class ListNode{
public:
    ListNode(int v):val(v), next(NULL), rand(NULL){}
public:
    int val;
    ListNode *next;
    ListNode *rand;
};

// 法一 利用map的方法 拷贝到map中再连起来
ListNode *CopyListRandom1(ListNode *head){
    unordered_map<ListNode*, ListNode *> m;
    ListNode *p = head;
    while(p){
        m[p] = new ListNode(p->val);
        p = p->next;
    }
    p = head;
    while(p){
        m[p]->next = m[p->next];
        m[p]->rand = m[p->rand];
        p = p->next;
    }
    return m[head];
}
// 法2
ListNode *CopyListRandom(ListNode *head){
    if(head == NULL){
        return NULL;
    }
    ListNode *cur = head;
    ListNode *nextNode = NULL;
    // 复制一个相同的节点 并把所有节点连起来
    while(cur){
        nextNode = cur->next;
        cur->next = new ListNode(cur->val);   
        cur->next->next = nextNode;
        cur = nextNode;
    }

    // 复制拷贝节点的rand指针
    ListNode *copyNode = NULL;
    cur = head;
    while(cur){
        nextNode = cur->next->next;
        copyNode = cur->next;
        copyNode->rand = cur->rand? cur->rand->next : NULL;
        cur = nextNode;
    }
    // 将两个链表分离
    cur = head;
    ListNode *res = cur->next;
    while(cur){
        nextNode = cur->next->next;
        copyNode = cur->next;
        cur->next = nextNode;
        copyNode->next = nextNode ? nextNode->next : NULL;
        cur = nextNode;
    } 
    return res;
}
void test(){
    ListNode *p = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    p->next = p1;
    p->rand = p2;
    p1->next = p2;
    p1->rand = NULL;
    p2->next = NULL;
    p2->rand = p;
    ListNode *p3 = CopyListRandom1(p);
    cout<<p3->rand->val<<endl;
    while(p3){
        cout<<"val: "<<p3->val<<" ";
        p3 = p3->next;
    }

}
int main(){
    test();
    system("pause");
    return 0;
}