#include"bits/stdc++.h"
using namespace std;
/*
    一块金条切成两半，是需要花费和长度数值一样的铜板的。比如长度为20的 金条，不管切成长度多大的两半，都要花费20个铜板。
    一群人想整分整块金条，怎么分最省铜板？
    例如:给定数组{10,20,30}，代表一共三个人，整块金条长度为10+20+30=60.
        金条要分成10,20,30三个部分。 如果， 先把长度60的金条分成10和50，花费60 再把长度50的金条分成20和30，
        花费50 一共花费110铜板。但是如果， 先把长度60的金条分成30和30，花费60 再把长度30金条分成10和20，花费30 一共花费90铜板。
    输入一个数组，返回分割的最小代价。
*/

// 贪心算法(哈夫曼编码求解) 每次都是合并最小的 合并后再放回 知道优先队列中只有一个元素 合并哈夫曼编码树的过程 合并完毕后 从上往下切
int cutGold(vector<int> &nums){
    if(nums.empty()){
        return 0;
    }
    // 优先队列 第一个参数：数据类型 第二个参数：容器类型 第三个参数：比较方法 greater 小根堆 less大根堆
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i = 0; i < nums.size(); i++){
        pq.push(nums[i]);
    }
    int result = 0;
    while(pq.size() > 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        pq.push(num1 + num2);
    }
    return pq.top();
}
int main(){
    vector<int> vec{20,10,30};
    int num = cutGold(vec);
    cout<<num<<endl;
    system("pause");
    return 0;
}