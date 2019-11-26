#include"bits/stdc++.h"
using namespace std;
// 桶排序 计数排序 基数排序
// 1.桶排序 计数排序
void BucketSort(vector<int> &nums){
    if(nums.size() < 2)return;
    int max = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > max)
            max = nums[i];
    }
    vector<int> vec(max+1, 0);
    for(int i = 0; i < nums.size(); i++){
        vec[nums[i]]++;
    }
    int j = 0;
    for(int i = 0; i < vec.size(); i++){
        while(vec[i]--){
            nums[j++] = i;
        }
    }
}

// 2.基数排序
void RadixSort(){}
void print(vector<int> nums){
    auto i = nums.begin();
    while(i != nums.end()){
        cout<<*i++<<" ";
    }
}
int main(){
    vector<int> vec;
    for(int i = 0; i < 500; i++){
        vec.push_back(rand() % 500);
    }
    BucketSort(vec);
    cout<<"桶排序"<<endl;
    print(vec);
    system("pause");
    return 0;
}