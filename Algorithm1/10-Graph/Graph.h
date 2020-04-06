//
// Created by leexsh on 2020/3/25.
//
#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

#include <vector>
// 边的类
class Edge
{
public:
    int val;       // 权重
    int from;      // 从哪里
    int to;         // 到哪里

    Edge(int v, int f, int t) : val(v),from(f),to(t)
    {};
};

class Node
{
public:
    int val;    // 节点值
    int in;     // rudu
    int out;    // chudu
    vector<Node*> nexts;    // 相连节点
    vector<Edge*> edges;    //  相连的边

    Node(int v)
    {
        val = v;
        in = 0;
        out = 0;
    }
};

class Graph {
public:
    map<int, Node*> nodes;
    set<Edge*> edges;
};


#endif //ALGORITHM_GRAPH_H
