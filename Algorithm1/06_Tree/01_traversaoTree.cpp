#include"bits/stdc++.h"
using namespace std;

/*
    二叉树的前序 中序和后序遍历 包括递归版本和非递归版本
    二叉树的层次打印
*/

// 二叉树的结构
class TreeNode{
public:
    TreeNode(int v) : val(v), left(NULL), right(NULL){}
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// 前序遍历-递归
void preOrderRec(TreeNode *head){
    if(head == NULL){
        return;
    }
    cout<<head->val<<" ";
    preOrderRec(head->left);
    preOrderRec(head->right);
}

// 前序遍历-非递归 借助栈
void preOrderNoRec(TreeNode *head){
    if(head == NULL){
        return;
    }
    stack<TreeNode*> s;
    s.push(head);
    while(!s.empty()){
        head = s.top();
        s.pop();
        cout<<head->val<<" ";
        if(head->right != NULL){
            s.push(head->right);
        }
        if(head->left != NULL){
            s.push(head->left);
        }
    }
}

// 中序遍历-递归
void inOrderRec(TreeNode *head){
    if(head == NULL){
        return;
    }
    
    inOrderRec(head->left);
    cout<<head->val<<" ";
    inOrderRec(head->right);
}

// 中序遍历-非递归
void inOrderNoRec(TreeNode *head){
    if(head){
        stack<TreeNode*> s;
        while(!s.empty() || head){
            if(head){
                s.push(head);
                head = head->left;
            }else
            {
                head = s.top();
                s.pop();
                cout<<head->val<<" ";
                head = head->right;
            }
        }
    }
}
// 后序遍历-递归
void postOrderRec(TreeNode *head){
    if(head == NULL){
        return;
    }
    
    postOrderRec(head->left);
    postOrderRec(head->right);
    cout<<head->val<<" ";
}

// 后序遍历-非递归 借助两个栈
void postOrderNoRec(TreeNode *head){
    if(head){
        stack<TreeNode*>  s1;
        stack<TreeNode*> s2;
        s1.push(head);
        while(!s1.empty()){
            head = s1.top();
            s1.pop();
            s2.push(head);
            if(head->left){
                s1.push(head->left);
            }
            if(head->right){
                s1.push(head->right);
            }
        }
        while(!s2.empty()){
            cout<<s2.top()->val<<" ";
            s2.pop();
        }
    }
}
// 后序遍历-非递归 借助一个栈
void postOrderNoRec1(TreeNode *head){
    if(head == NULL){
        return;
    }
    stack<TreeNode*> s;
    TreeNode *pMark;
    while(head || !s.empty()){
        // 压到底
        while(head){
            s.push(head);
            head = head->left;
        }
        // 如果他的you NULL或者右边标记了  就弹出
        if(s.top()->right == NULL || s.top()->right == pMark)
		{
			//弹出 打印 标记
            pMark = s.top();
            s.pop();
			cout<<pMark->val<<" ";
		}
		else
		{
			head = s.top()->right;
		}
    }

}

// 二叉树的顺序遍历
void seQueTraversal(TreeNode *head){
    if(head == nullptr){
        return;
    }
    queue<TreeNode*> que;
    que.push(head);
    while(!que.empty()){
        head = que.front();
        que.pop();
        cout<<head->val<<" ";
        if(head->left){
            que.push(head->left);
        }
        if(head->right){
            que.push(head->right);
        }
    }
}
int main(){
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    
    // preOrderNoRec(head);
    // cout<<endl;
    // preOrderRec(head);
    // cout<<endl;
    // inOrderNoRec(head);
    // cout<<endl;
    // inOrderRec(head);
    // cout<<endl;
    postOrderNoRec1(head);
    cout<<endl;
    postOrderRec(head);
    cout<<endl;
    seQueTraversal(head);
    
    
    system("pause");
    return 0;
}


