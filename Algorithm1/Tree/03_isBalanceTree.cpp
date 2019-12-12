#include "bits/stdc++.h"
using namespace std;
/* 
    给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
    示例 1:
        给定二叉树 [3,9,20,null,null,15,7]
            3
           / \
          9  20
          /  \
         15   7
        返回 true 。
    示例 2:
        给定二叉树 [1,2,2,3,3,null,null,4,4]
           1
          / \
         2   2
          / \
         3   3
          / \
         4   4
        返回 false 。
*/

/*
思路：

 */
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 左神方法
struct ReturnData{
    bool isBala;
    int height;
    ReturnData(bool b, int v) : isBala(b), height(v){}
};
ReturnData process(TreeNode *root){
    if(root == nullptr){
        return ReturnData(true, 0);
    }
    ReturnData leftData = process(root->left);
    if(!leftData.isBala){
        return ReturnData(false, 0);
    }
    ReturnData rightData = process(root->right);
    if(!rightData.isBala){
        return ReturnData(false, 0);
    }
    if(abs(rightData.height - leftData.height) > 1){
        return ReturnData(false, 0);
    }
    return ReturnData(true, max(leftData.height, rightData.height)+1);
}

bool isBalance(TreeNode *root){
    return process(root).isBala;
}

// leetcode 解法
bool isBalance(TreeNode *root){
    if(root == nullptr){
        return true;
    }
    int deepth = abs(getDeepth(root->left) - getDeepth(root->right));
    return deepth <= 1 && isBalance(root->left) && isBalance(root->right);
}
int getDeepth(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    return max(getDeepth(root->left),getDeepth(root->right)) + 1;
}
int main(){
    TreeNode *pp = nullptr;
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(27);
    // cout<<isBalanced(pp);
    system("pause");
    return 0;
}