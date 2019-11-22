#include"bits/stdc++.h"
using namespace std;

//动态数组求中位数
// 输入为不断地数字流，实时显示出当前已经输入的数字序列的中位数

// 求中位数的方法很多，对于大数据量最经典是桶的计数方法，但是对于这个问题不适用，因为数据是不断变化的

// 可以用最大堆和最小堆来解答这个问题：
// 
// 1.假设当前的中位数为m，其中最大堆维护的是<=m的数字序列，最小堆维护的是>=m的数字序列，但是两个堆都不包含m

// 2.当新的数字到达时，比如为a，将a与m进行比较，若a<=m 则将其加入到最大堆中，否则将其加入到最小堆中

// 3.如果此时最小堆和最大堆的元素个数的差值>=2 ，则将m加入到元素个数少的堆中，然后从元素个数多的堆将根节点赋值到m，
// 最后重建两个最大堆和最小堆，返回到2
int main(){

    system("pause");
    return 0;
}