#include "bits/stdc++.h"
using namespace std;
/* 
已知一棵完全二叉树，求其节点的个数
要求：时间复杂度低于O(N)，N为这棵树的节点个数
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int nodeNum(TreeNode *head){
    if(head == nullptr){
        return 0;
    }
    return bs(head, 1, mostLeftLevel(head, 1));
}
int bs(TreeNode* node, int l, int h) {
	if (l == h) {
		return 1;
	}
	if (mostLeftLevel(node->right, l + 1) == h) {
		return (1 << (h - l)) + bs(node->right, l + 1, h);
	} else {
		return (1 << (h - l - 1)) + bs(node->left, l + 1, h);
	}
}
int mostLeftLevel(TreeNode* node, int level) {
	while (node != nullptr) {
		level++;
		node = node->left;
	}
	return level - 1;
}
int main(){

    return 0;
}