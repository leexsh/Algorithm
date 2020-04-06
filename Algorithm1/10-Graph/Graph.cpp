//
// Created by leexsh on 2020/3/25.
//

#include "Graph.h"
Graph createGraph(vector<vector<int>> vec)
{
    Graph graph = new Graph;
    for(auto i : vec){
        int weight = vec[i][0];
        int from = vec[i][1];
        int to = vec[i][2];
        if(!graph.nodes.count(from)){
            graph.nodes.insert(from, new Node(from));

        }
        if(!graph.nodes.count(to)){
            graph.nodes.insert(to, new Node(to));

        }
        Node fromNode = graph.nodes[from];
        Node toNode = graph.nodes[to];
        Edge newEd = new Edge(weight,fromNode, toNode);
        fromNode.nexts.insert(toNode);
        fromNode.out++;
        toNode.in++;
        fromNode.edges.add(newEd);
        graph.edges.add(newEd);
//        for(){}
    }
    return graph;
    
}