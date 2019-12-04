#include"bits/stdc++.h"
using namespace std;

/*
    将单向链表按某值划分成左边小、中间相等、右边大的形式
    【题目】 给定一个单向链表的头节点head，节点的值类型是整型，再给定一个整 数pivot。
        实现一个调整链表的函数，将链表调整为左部分都是值小于 pivot的节点，
        中间部分都是值等于pivot的节点，右部分都是值大于 pivot的节点。除这个要求外，
        对调整后的节点顺序没有更多的要求。 例如：链表9->0->4->5->1，pivot=3。 
        调整后链表可以是1->0->4->9->5，也可以是0->1->9->5->4。总之，
        满足左部分都是小于3的节点，中间部分都是等于3的节点（本例中这个部分为空），
        右部分都是大于3的节点即可。对某部分内部的节点顺序不做 要求。
    进阶： 在原问题的要求之上再增加如下两个要求。在左、中、右三个部分的内部也做顺序要求，
        要求每部分里的节点从左到右的顺序与原链表中节点的先后次序一致。 
        例如：链表9->0->4->5->1，pivot=3。调整后的链表是0->1->9->4->5。 
        在满足原问题要求的同时，左部分节点从左到右为0、1。在原链表中也 是先出现0，后出现1；
        中间部分在本例中为空，不再讨论；右部分节点 从左到右为9、4、5。
        在原链表中也是先出现9，然后出现4，最后出现5。如果链表长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)。
*/
class ListNode{
public:
    ListNode(int v) : val(v), next(NULL){}
public:
    
    int val;
    ListNode *next;
};
//荷兰国旗的方法
void partition(vector<ListNode*> &pv, int target);
ListNode *SmallEqualBig(ListNode *head, int target){
    if(head == NULL){
        return head;
    }
    ListNode *p = head;
    vector<ListNode*> vec;
    while(p){
        vec.push_back(p);
        p = p->next;
    }
    partition(vec, target);
    int i;
    for(i = 1; i < vec.size(); i++){
        vec[i-1]->next = vec[i];
    }
    vec[i-1]->next = NULL;
    return vec[0];
}
void partition(vector<ListNode*> &pv, int target){
    int left = -1;
    int right = pv.size();
    int index = 0;
    while(index != right){
        if(pv[index]->val < target)
        {
            ListNode *p = pv[index];
            pv[index] = pv[++left];
            pv[left] = pv[index++];

        }
        else if(pv[index]->val == target)
        {
            index++;
        }
        else{
            ListNode *p = pv[--right];
            pv[right] = pv[index];
            pv[index] = p;
        }
    }
}
// 三个指针的方法 分别串小于、等于和大于target的数
ListNode *SmallEqualBig1(ListNode *head, int target){
    ListNode *smallHead = NULL, *smallTail = NULL;//小于target的头尾
    ListNode *equalHead = NULL, *equalTail = NULL;//等于target的头尾
    ListNode *bigHead = NULL, *bigTail = NULL;//大于target的头尾
    ListNode *next = NULL;//当前指针的下一个
    while(head){
        next = head->next;
        head->next = NULL;
        if(head->val < target)
        {
            if(smallHead == NULL){
                smallHead = head;
                smallTail = head;
            }
            else
            {
                smallTail->next = head;
                smallTail = head;
            }
        }
        else if(head->val == target)
        {
            if(equalHead == NULL){
                equalHead = head;
                equalTail = head;
            }else
            {
                
                equalTail->next = head;
                equalTail = head;
            }
            
        }
        else
        {
            if(bigHead == NULL)
            {
                bigHead = head;
                bigTail = head;
            }else
            {
                bigTail->next = head;
                bigTail = head;
            }
            
        }
        head = next;
    }
    
    //small和equal连接
    if(smallTail != NULL){
        smallTail->next = equalHead;
        equalTail = equalTail == NULL ? smallTail : equalTail;
    }
    // equal 和 big 连接
    if(equalTail != NULL){
        equalTail->next = bigHead;
    }
    //返回
    return smallHead ? smallHead : equalHead ? equalHead : bigHead;

}
void print(ListNode *l){
    while(l){
        cout<<l->val<<" ";
        l = l->next;
    }
}
void test01(){
    ListNode *p = new ListNode(9);  
    ListNode *p1 = new ListNode(0);
    p->next = p1;
    ListNode *p2 = new ListNode(4);
    p->next->next = p2;
    ListNode *p3 = new ListNode(5);
    p->next->next->next = p3;
    ListNode *p4 = new ListNode(1);
    p->next->next->next->next = p4;
    ListNode *ppr = SmallEqualBig1(p,3);
    print(ppr);
}
int main(){
    test01();
    system("pause");
    return 0;
}