#include"bits/stdc++.h"
using namespace std;
// 前缀树的节点
class TireNode{
public:
    TireNode() : path(0), end(0){
        memset(nexts, 0, sizeof(nexts));
    }
    ~TireNode(){
    }

    TireNode *nexts[26];//保存26个字母的数组
    int path;//经过某一个节点的次数
    int end;//以某一个节点结尾的次数
};

// 前缀树
class TireTree{
public:
    // 根节点
    TireNode *root;
    TireTree(){
        root = new TireNode;
    }
    ~TireTree(){
        delete root;
        root = NULL;
    }

    // 向字典树中插入一个字符串
    void insert(string word){
        if(word.empty()){
            return;
        }
        // 定义一个节点指向根节点
        TireNode *node = root;
        int index = 0;
        for(int i = 0; i < word.size(); i++){
            // 插入的位置
            index = word[i] - 'a';
            if(node->nexts[index] == nullptr){
                node->nexts[index] = new TireNode;
            }
            node = node->nexts[index];
            // 经过该节点+1
            node->path++;
        }
        // 以该节点结尾+1
        node->end++;
    }
   
    // 寻找以word字符串在字典树中出现的次数
    int search(string word){
        if(word.empty()){
            return 0;
        }
        int index = 0;
        TireNode *node = root;
        for(int i = 0; i < word.size(); i++){
            index = word[i] - 'a';
            if(node->nexts[index] == nullptr){
                return 0;
            }
            node = node->nexts[index];
        }
        // 找到以该字符结尾的个数
        return node->end;
    }
    // 在字典树中删除一个字符串
    void deleteNode(string word){
        if(search(word) != 0){
            int index = 0;
            TireNode *node = root;
            for(int i = 0; i < word.size(); i++){
                index = word[i] - 'a';
                --node->nexts[index]->path;
                if(node->nexts[index]->path == 0){
                    // 删除节点 不然内存泄漏
                    destory(node->nexts[index]);
                    return;

                }
                node = node->nexts[index];
            }
            --node->end;
        }
    }
    // 如果某一个节点的path为0 删除他下面的所有节点
    void destory(TireNode* root)
    {
        if(root == nullptr)
            return ;
        for(int i=0;i<26;i++)
        {
            destory(root->nexts[i]);
        }
        delete root;
        root = nullptr;
    }
    // 查询以某一个字符串为前缀的数量
    int prefixNumber(string word){
        if(word.empty()){
            return 0;
        }
        int index = 0;
        TireNode *node = root;
        for(int i = 0; i < word.size(); i++){
            index = word[i] - 'a';
            if(node->nexts[index] == NULL){
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }
};
int main(){
    TireTree t;
    t.insert("lu");
    cout<<t.search("lu")<<endl;
    system("pause");
    return 0;
}