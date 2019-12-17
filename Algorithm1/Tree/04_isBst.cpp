#include "bits/stdc++.h"
using namespace std;
/* 
 给定一个二叉树，判断其是否是一个有效的二叉搜索树BST
*/

/*

 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBST(TreeNode *head){
    stack<TreeNode*> s;
    int temp = INT_MIN;
    while(!s.empty() || head){
        while (head)
        {
            s.push(head);
            head = head->left;
        }
        head = s.top();
        s.pop();
        if(head->val < temp){
            return false;
        }
        temp = head->val;
        if(head->right){
            head = head->right;
        }
    }
    return true;
}

int main(){
   
    system("pause");
    return 0;
}