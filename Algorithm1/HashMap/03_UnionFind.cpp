#include"bits/stdc++.h"
using namespace std;
/*
    并查集：
        可以快速的检测两个元素是否在一个集合中
        可以快速的和并两个集合

*/
// 集合中的元素
class Node{};

// 并查集
class UnionFindSet{
public:
    // 构造方法
    UnionFindSet(set<Node*> nodes){
        makeSet(nodes);
    }
    // 判断两个元素是否在一个集合中
    bool isSameSet(Node *a, Node *b){
        return findFather(a) == findFather(b);
    }

    // 将两个元素所在的集合进行合并
    void unionSet(Node *a, Node *b){
        if(a == nullptr || b == nullptr){
            return;
        }
        // 找到头
        Node *aHead = findFather(a);
        Node *bHead = findFather(b);
        if(aHead != bHead){
            int aSize = numMap[a];
            int bSize = numMap[b];
            // 判断大小  把小的合并到大的里面
            if(aSize <= bSize){
                fatherMap[aHead] = bHead;
                numMap[bHead] = aSize + bSize; 
            }
            else
            {
                fatherMap[bHead] = aHead;
                numMap[aHead] = bSize + aSize; 
            }
        }
    }
private:
    // 构建集合的方法
    void makeSet(set<Node*> nodes){
        fatherMap.clear();
        numMap.clear();
        for(auto node : nodes){
            fatherMap[node] = node;
            numMap[node] = 1;
        }
    }
    // 递归找某一个节点的父节点 同时 将该节点及上面的元素都连接到最父节点的下面
    Node *findFather(Node * node){
        Node* father = fatherMap[node];
        while(father != node){
            father = findFather(father);
        }
        fatherMap[node] = father;
        return father; 
    }
   
private:
    // 当前节点与其父节点的映射
    map<Node*, Node *> fatherMap;
    // 当前节点与集合中的元素个数的映射
    map<Node*, int> numMap;
};
int main(){
    system("pause");
    return 0;
}