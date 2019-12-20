#include"bits/stdc++.h"
using namespace std;
/*
 给定一个由 1（陆地）和 0（水）组成的的二维网格，计算岛屿的数量。
    一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
    示例 1:
        输入:
        11110
        11010
        11000
        00000
        输出: 1
    示例 2:
        输入:
        11000
        11000
        00100
        00011
        输出: 3
*/
// 岛屿问题 可以用深度搜索 也可以用并查集 并查集用的是hash的知识
int numIslands(vector<vector<int>>& grid) {
    if(grid.empty()){
        return 0;
    }
    int res = 0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            if(grid[i][j] == 1){
                res++;
                infect(grid, i, j, grid.size(), grid[0].size);
            }
        }
    }
}
void infect(vector<vector<int>> &nums, int i, int j, int L, int W){
    if(i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() || nums[i][j] != 1){
        return;
    }
    nums[i][j] = 2;
    infect(nums, i - 1, j , L, W);
    infect(nums, i + 1, j , L, W);
    infect(nums, i, j - 1, L, W);
    infect(nums, i, j + 1, L, W);
}
int main(){
    system("pause");
    return 0;
}