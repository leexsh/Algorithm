#include"bits/stdc++.h"
using namespace std;
/* 
    题目：数据流中的中位数
    中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
    例如，
        [2,3,4] 的中位数是 3
        [2,3] 的中位数是 (2 + 3) / 2 = 2.5
    设计一个支持以下两种操作的数据结构：
        void addNum(int num) - 从数据流中添加一个整数到数据结构中。
	    double findMedian() - 返回目前所有元素的中位数。
    示例：
        addNum(1)   
        addNum(2)   
        findMedian() -> 1.5
        addNum(3) 
        findMedian() -> 2
    进阶:
        如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
	    如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/

/*
思路：
    堆的思想
    大根堆：保存的所有元素都比堆顶小 用来保存比中位数小的元素
    小根堆：保存的所有元素都比堆顶大 用来保存比中位数大的元素
    如果奇数个元素 肯定有个堆比另一个多一个元素 多的那个数就是中位数
    如果偶数个元素  两个堆顶元素的平均数
 */
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > minHeap;//小根堆 放所有比中位数大的
    priority_queue<int, vector<int>, less<int> > maxHeap; // 大根堆 放所有比中位数小的
    /** initialize your data structure here. */
    MedianFinder() {
    }

    // 调整
    void modifyHeapSize(){
        // 始终不能让两个堆的差值大于2
        if(minHeap.size() == maxHeap.size() + 2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() == minHeap.size() + 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    // 添加一个数的过程
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        if(num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else
        {
            if(minHeap.empty()){
                minHeap.push(num);
                return;
            }
            if(num > minHeap.top()){
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }
    }
    // 返回中位数
    double findMedian() {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        if(maxHeap.empty() && minHeap.empty()){
            return 0;
        }
        if(maxHeap.empty() && !minHeap.empty()){
            return minHeap.top();
        }
        if(!maxHeap.empty() && minHeap.empty())
        {
            return maxHeap.top();
        }
        int maxHead = maxHeap.top();
        int minHead = minHeap.top();
        if(((maxSize + minSize) & 1) == 0){
            return (maxSize + minSize) * 0.5;
        }
        return maxSize > minSize ? maxHead : minHead;
    }
};
int main(){
    system("pause");
    return 0;
}