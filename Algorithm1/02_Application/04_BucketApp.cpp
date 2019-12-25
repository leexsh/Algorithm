#include"bits/stdc++.h"
using namespace std;
//桶排序的应用
// 给定一个数组，求如果排序之后，相邻两数的最大差值，要求时 间复杂度O(N)，且要求不能用非基于比较的排序
int Bucket(int num, int size, int min, int max);
int MaxGap(vector<int> nums){
    if(nums.size() < 2){
        return 0;
    }
    int size = nums.size() - 1;
    int max = nums[0];
    int min = nums[0];
    //找到数组的最大值和最小值
    for(int i = 1;i<=size; i++){
        max = nums[i] > max ? nums[i] : max;
        min = nums[i] < min ? nums[i] : min;
    }
    // 最大值和最小值相等
    if(max == min)
        return 0;
    vector<bool> hasNum(size+1);
    vector<int> maxNum(size + 1);
    vector<int> minNum(size + 1);
    int bucket = 0;
    //放入桶中
    for(int i = 0; i <= size; i++){
        bucket = Bucket(nums[i], size, min, max);
        //桶中灭有数 最大值和最小值就是放入桶中的数
        if(!hasNum[bucket]){
            maxNum[bucket] = nums[i];
            minNum[bucket] = nums[i];
        }
        //否则的话进行比较
        else if(hasNum[bucket]){
            maxNum[bucket]= maxNum[bucket] > nums[i] ? maxNum[bucket] : nums[i];
            minNum[bucket] = minNum[bucket] <nums[i] ? minNum[bucket] : nums[i];
        }
        //标志位置为true
        hasNum[bucket] = true; 
    }
    int res = 0;
    //循环找最大
    int lastMax = maxNum[0];
    for(int i = 1; i <= size; i++){
        if(hasNum[i]){
            res = res > minNum[i] - lastMax ? res : minNum[i] - lastMax;
            lastMax = maxNum[i]; 
        }
    }
	return res;
}
//将每个数放入桶中
int Bucket(int num, int size, int min, int max){
    return (int)((num - min)/(max - min) * size);
}
int main(){

    vector<int> num{2,3,4,5,6,19,80};
    cout<<MaxGap(num)<<endl;
    system("pause");
    return 0;
}