#include"bits/stdc++.h"
using namespace std;
/*
LeetCode 502
    输入： 
        参数1，正数数组costs costs[i]表示i号项目的花费
        参数2，正数数组profits profits[i]表示i号项目在扣除花费之后还能挣到的钱(利润)
        参数3，正数k  k表示你不能并行、只能串行的最多做k个项目
        参数4，正数m m表示你初始的资金
    说明：你每做完一个项目，马上获得的收益，可以支持你去做下一个项目。
    输出：你最后获得的最大钱数。
*/
// 贪心算法
// 构造节点
class Node{
public:
    Node(){}
    Node(int c, int p):cost(c), profit(p){}
public:
    int cost;
    int profit;
};

// 根据利润构造大根堆
struct MaxCompare{
    bool operator()(Node n1, Node n2){
        return n1.profit < n2.profit;
    }
};
// 根据花费构造小根堆
struct MinCompare{
    bool operator()(Node n1, Node n2){
        return n1.cost > n2.cost;
    }
};

int findMax(int k, int m, vector<int> &cost, vector<int>& profit){
    // 构造节点 并把节点全部放进数组中
    vector<Node> vec;
    for(int i = 0; i < cost.size(); i++){
        vec.push_back(Node(cost[i], profit[i]));
    }
    // 根据花费构造的花费小根堆
    priority_queue<Node, vector<Node>, MinCompare> minCost;
    // 根据利润构造的大根堆
    priority_queue<Node, vector<Node>, MaxCompare> maxPro;
    // 全部放入小根堆中
    for(int i = 0; i < vec.size(); i++){
        minCost.push(vec[i]);
    }
    // cout<<"cost small "<<endl;
    // while(!minCost.empty()){
    //     cout<<"cost:"<<minCost.top().cost<<" pro"<<minCost.top().profit<<endl;
    //     minCost.pop();
    // }
    // for(int i = 0; i < vec.size(); i++){
    //     minCost.push(vec[i]);
    // }
    // cout<<"pro big :"<<endl;
    // while(!minCost.empty()){
    //     maxPro.push(minCost.top());
    //     minCost.pop();
    // }
    // while(!maxPro.empty()){
    //     cout<<"cost:"<<maxPro.top().cost<<" pro"<<maxPro.top().profit<<endl;
    //     maxPro.pop();
    // }
    // 把当前能做的项目 按照利润放入大根堆中 做利润最大的项目
    for(int i  = 0; i < k; i++){
        while(!minCost.empty() && minCost.top().cost <= m ){
            maxPro.push(minCost.top());
            minCost.pop();
        }
        // 没得做了
        if(maxPro.empty()){
            return m;
        }

        m += maxPro.top().profit;
        maxPro.pop();
    }
    return m;

} 
int main(){
    vector<int> cost{3,2,1};
    vector<int> pro{1,2,3};
    // findMax(2,0,cost, pro);
    system("pause");
    return 0;
}