#include"bits/stdc++.h"
using namespace std;
/*
“之”字形打印矩阵
【题目】 给定一个矩阵matrix，按照“之”字形的方式打印这
个矩阵，例如： 1 2 3 4 5 6 7 8 9 10 11 12
“之”字形打印的结果为：1，2，5，9，6，3，4，7，10，11，
8，12
【要求】 额外空间复杂度为O(1)
*/
  
void PrintLevel(vector<vector<int>> &nums, int a,int b, int c, int d, bool f);
// 从起点开始 (a,b)横着走 横着走到头往下走 (c,d)竖着走 (c,d)走到最底下往右走   
void ZhiPrint(vector<vector<int>> &nums){
    if(nums.empty()){
        return;
    }
   	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
   	int endS = nums.size() - 1;
	int endH = nums[0].size() - 1;
    bool f = false;
    while(a != endS + 1){
        PrintLevel(nums, a,b,c,d,f);
        a = b == endH ? a+1 : a;
        b = b == endH ? b: b+1;
        
        d = c == endS ? d+1 : d;
        c = c ==endS ? c: c+1;
        f = !f;
    }
    	// int a = 0;
		// int b = 0;
		// int c = 0;
		// int d = 0;
		// int endS = nums.size() - 1;
		// int endH = nums[0].size() - 1;
        // bool f = false;
		// while (a != endS + 1) {
		// 	PrintLevel(nums, a, b, c, d, f);
		// 	a = b == endH ? a + 1 : a;
		// 	b = b == endH ? b : b + 1;
            
		// 	d = c == endS ? d + 1 : d;
		// 	c = c == endS ? c : c + 1;
		// 	f = !f;
		// }

}
void PrintLevel(vector<vector<int>> &nums, int a,int b, int c, int d, bool f){
    if(f)
    {
        while(a != c+1){
            cout<<nums[a++][b--]<<" ";
        }
    }
    else
    {
        while(c != a-1){
            cout<<nums[c--][d++]<<" ";
        }
    }
    
}
void test01(){
    vector<vector<int>> v{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    ZhiPrint(v);
}
int main(){
    test01();
    system("pause");
    return 0;
}