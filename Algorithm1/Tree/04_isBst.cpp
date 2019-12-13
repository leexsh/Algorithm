#include "bits/stdc++.h"
using namespace std;
/* 
 给定一个二叉树，判断其是否是一个有效的完全二叉树(CBT)。
*/

/*
思路：判断一个树是不是一个完全二叉树 主要有以下几个情况
     O          O        O  
    / \        / \      / \
    ×  O       O  ×    ×  ×
    1.          2.       3.
    很明显 1.不是完全二叉树     
            如果是完全二叉树 则从该节点起的所有节点都是叶子节点  bool类型的f就是为了标志叶子节点从那里开始
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCBT(TreeNode *node){
    if(node == nullptr){
        return true;
    }
    deque<TreeNode*> dq;
    TreeNode *l, *r;
    dq.push_back(node);
    bool f = false;
    while(!dq.empty()){
        node = dq.front();
        dq.pop_front();
        l = node->left;
        r = node->right;
        // 如果开始叶子节点 以后还有节点有子节点的话 肯定false  还有一种情况就是有右无左 也是false
        if((f && (l != nullptr || r != nullptr)) || 
                (l == nullptr && r != nullptr)){
            return false;
        }
        if(l){
            dq.push_back(l);
        }
        if(r){
            dq.push_back(r);
        }
        // 开始叶子节点的情况 标志置为true
        else if((l == NULL && r == NULL) || (l != nullptr && r == nullptr)){
            f = true;
        }
    }
    return true;
}


int main(){
   
    system("pause");
    return 0;
}