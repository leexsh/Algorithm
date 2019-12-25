#include"bits/stdc++.h"
using namespace std;
/*
转圈打印矩阵
【题目】 给定一个整型矩阵matrix，请按照转圈的方式打印它。
例如： 1 2 3 4 5 6 7 8 9 10 11 12 13 14
15 16 打印结果为：1，2，3，4，8，12，16，15，14，13，9，
5，6，7，11， 10
【要求】 额外空间复杂度为O(1)。
*/
void printEdge(vector<vector<int>>&nums, int a, int b, int c, int d);
void printMatrixSpiralOrder(vector<vector<int>> &nums){
    if(nums.empty()){
        return;
    }
    int a = 0; 
    int b = 0;
    int c = nums.size()-1;
    int d = nums[0].size()-1;
    while(a <= c && b <= d){
        printEdge(nums, a++, b++, c--, d--);
    }
}
// 先打印一圈 (a,b)是左上角的点 (c,d)是右下角的点
void printEdge(vector<vector<int>>&nums, int a, int b, int c, int d){
    //矩阵是一行
    if(a == c){
        for(int i = d; i <=d; i++){
            cout<<nums[a][i]<<" ";
        }
    }
    // 矩阵是一列
    else if(b == d){
        for(int i = a; i <= c; i++){
            cout<<nums[i][b]<<" ";
        }
    }
    else{
        //列
        int heng = b;
        // 行
        int shu = a;
        // 从(a,b)打印到(a,d)
        while(heng != d){
            cout<<nums[a][heng]<<" ";
            heng++;
        }
        // 从(a,d)打印到(c,d)
        while(shu != c){
            cout<<nums[shu++][d]<<" ";
        }
        // cout<<"heng = "<<heng<<" shu = "<<shu<<endl;
        // 从(c,d)打印到(c,b)
        while(heng != b){
            // cout<<nums[c][heng--]<<" ";
            cout<<nums[c][heng--]<<" ";
        }
        // // 从(c,b)打印到(a,b)
        while(shu != a){
            cout<<nums[shu--][b]<<" ";
        }
    }
}

void test01(){
    vector<vector<int>> vec{{1,2,3,4,},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printMatrixSpiralOrder(vec);
}
int main(){
    test01();
    system("pause");
    return 0;
}