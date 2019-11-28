#include"bits/stdc++.h"
using namespace std;
/*
旋转正方形矩阵
【题目】 给定一个整型正方形矩阵matrix，请把该矩阵调整成
顺时针旋转90度的样子。
【要求】 额外空间复杂度为O(1)。
*/
void ratoteEdge(vector<vector<int>> &nums, int a, int b, int c, int d);
void print(vector<vector<int>> &nums){
    if(nums.empty()){
        return;
    }
    int a = 0;
    int b = 0;
    int c = nums.size() - 1;
    int d = nums[0].size() - 1;
    while(a<c){
        ratoteEdge(nums, a++, b++, c--, d--);
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[1].size(); j++){
            cout<<nums[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//(a,b)是左上角的点 (c, d)是右下角的点 从(a,b)打印到(c,d)然后再从(c, d)打印回(a,b)
void ratoteEdge(vector<vector<int>> &nums, int a, int b, int c, int d){
    int edge = d - b;
    int temp = 0;
    for(int i = 0; i != edge; i++){
        temp = nums[a][b+i];
        nums[a][b+i] = nums[c-i][b];
        nums[c-i][b] = nums[c][d-i];
        nums[c][d-i] = nums[a+i][d];
        nums[a+i][d] = temp;
    }
}
void test01(){
   vector<vector<int>> v{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   print(v); 
}
int main(){
    test01();
    system("pause");
    return 0;
}