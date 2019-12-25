#include"bits/stdc++.h"
using namespace std;
/*
在行列都排好序的矩阵中找数
【题目】 给定一个有N*M的整型矩阵matrix和一个整数K，
matrix的每一行和每一 列都是排好序的。实现一个函数，判断K
是否在matrix中。 例如： 0 1 2 5 2 3 4 7 4
4 4 8 5 7 7 9 如果K为7，返回true；如果K为6，返
回false。
【要求】 时间复杂度为O(N+M)，额外空间复杂度为O(1)。
*/
//(a,b)是右上角的点 k == nums[a][b]返回 k > nums[a][b] 往下找  k<nums[a][b]往左找
bool FindNum(vector<vector<int>> &nums, int k){
    if(nums.empty()){
        return false;
    }
    int a = 0;
    int b = nums[0].size() - 1;
    while(a <= nums.size() - 1 && b >= 0){
        if(nums[a][b] == k){
            return true;
        }
        else if(nums[a][b] < k){
            a++;
        }
        else
        {
            b--;
        }
        
    }
    return false;
}
int main(){

    system("pause");
    return 0;
}