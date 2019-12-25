#include"bits/stdc++.h"
using namespace std;
/*
    在二叉树中找到一个节点的后继节点
    【题目】 现在有一种新的二叉树节点类型如下：
    public class Node { public int value; public Node left;
    public Node right; public Node parent;
    public Node(int data) { this.value = data; }
    }
    该结构比普通二叉树节点结构多了一个指向父节点的parent指针。假设有一 棵Node类型的节点组成的二叉树，
    树中每个节点的parent指针都正确地指向 自己的父节点，头节点的parent指向null。只给一个在二叉树中的某个节点 node，
    请实现返回node的后继节点的函数。在二叉树的中序遍历的序列中， node的下一个节点叫作node的后继节点。
*/
// 节点
class TreeNode{
public:
    TreeNode(int v) : val(v),  left(NULL), right(NULL), parent(NULL){}
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};
// 找后继节点

// 找右子树的最左的节点
TreeNode *findTheLeftNode(TreeNode *node){
    if(node == NULL){
        return NULL;
    }
    while(node->left){
        node = node->left;
    }
    return node;
}
TreeNode * findLastNode(TreeNode *node){
    // 树空 就返回空
    if(node == NULL){
        return NULL;
    }

    // 如果这个节点的右子树存在的话 那么他的后继节点就是他右孩子上的最左的节点
    if(node->right){
        return findTheLeftNode(node->right);
    }
    // 如果这个节点不存在右孩子 那么他的后继节点就是一直往上找 找到某个节点是他parent节点的左孩子为止 那么parent节点就是他的后继节点
    else
    {
        TreeNode *pParent = node->parent;
        while(pParent != NULL && pParent->left != node){
            node = pParent;
            pParent = pParent->parent;
        }
        return pParent;
    }
}

// 找前驱节点
TreeNode *findTheRightNode(TreeNode *node){
    if(node == nullptr){
        return nullptr;
    }
    while (node->right)
    {
        node = node->right;
    }
    return node;
    
}
TreeNode *findPreNode(TreeNode *node){
    if(node == NULL){
        return nullptr;
    }
    if(node->left){
        return findTheRightNode(node);
    }
    else
    {
        TreeNode *pParent = node->parent;
        while(pParent != nullptr && pParent->right != node){
            node = pParent;
            pParent = node->parent;
        }
        return pParent;
    }
    
}

int main(){
    system("pause");
    return 0;
}