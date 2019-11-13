#include"bits/stdc++.h"
using namespace std;
//快速排序

// 经典快排
void sort1(vector<int>&, int, int);
int partition1(vector<int>&, int,int);

void quicksort1(vector<int> &nums){
    // 数组为空
    if(nums.size() == 0){
        return;
    }
    // 排序
    sort1(nums, 0, nums.size() - 1);
}
// 排序
void sort1(vector<int> &nums, int low, int high){
    if(low < high){
        int num = partition1(nums, low, high);
        sort1(nums, low, num-1);
        sort1(nums, num+1,high);
    }
}
// 将数分开的过程
int partition1(vector<int>&nums, int low, int high){
    // left是分界线
    int left = low - 1;
    int ans = nums[high];
    int temp;
    while(low < high){
        // 小于等于left的都放在left的左边 大于left的都放在left的右边
        if(nums[low] <= ans){
            temp = nums[++left];
            nums[left] = nums[low];
            nums[low++] = temp;
        }
        else{
            low++;
        }
    }
    // 将high放在合适的位置
    nums[high] = nums[++left];
    nums[left] = ans; 
    return left;
}


void print(vector<int> nums){
    auto i = nums.begin();
    while(i != nums.end()){
        cout<<*i++<<" ";
    }
}

//交换数组中的两个数
void swap(vector<int>&nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
//采用荷兰国旗和选择随机一个数改进的随机快速排序
void sort2(vector<int>&, int, int);
pair<int, int> partition2(vector<int>&, int,int);
void quicksort2(vector<int> &nums){
    if(nums.size() <= 1)
        return;
    sort2(nums, 0, nums.size() - 1);
}
void sort2(vector<int> &nums, int low, int high){
    if(low < high){
        // 产生一个随机数跟最后一个数进行交换
        swap(nums, low + rand()%(high - low + 1), high);
        pair<int, int> p = partition2(nums, low, high);
        sort2(nums, low, p.first - 1);
        sort2(nums, p.second+1, high);
    }
}

pair<int, int> partition2(vector<int>&nums, int low,int high){
    // left的左边都是比ans小的数 右边都是等于ans的数
    int left = low - 1;
    // right的左边都是等于ans的数 右边都是大于ans的数
    int right = high;
    int ans = nums[high];
    int temp;
    // 分组的过程
    while(low < right){
        if(nums[low] < ans)
        {
            swap(nums,++left, low++);
            // temp = nums[++left];
            // nums[left] = nums[low];
            // nums[low++] = temp;
        }
        else if(nums[low] > ans)
        {
            swap(nums, --right, low);
            // temp = nums[--right];
            // nums[right] = nums[low];
            // nums[low] = temp;
        }
        else
        {
            low++;
        }
        
    }
    // nums[high] = nums[right];
    // nums[right] = temp;
    // 将ans放在等于的ans的最后一个
    swap(nums, high, right);
    // 返回一个pair对 first保存第一个等于ans的数 second保存最后一个等于ans的数
    pair<int, int> p(left+1, right);
    return p;
}
<<<<<<< HEAD
// 将pair改为数组 实现相同的改进的随机快排
void sort3(vector<int>&nums, int low, int high);
vector<int> partition3(vector<int> &nums, int low, int high);
void quicksort3(vector<int> &nums){
    if(nums.size() <2)
        return;
    sort3(nums, 0, nums.size() - 1);
}
void sort3(vector<int>&nums, int low, int high){
    if(low < high){
        swap(nums, high, low + rand() % (high - low + 1));
        vector<int> vec = partition3(nums, low, high);
        sort3(nums, low, vec[0] - 1);
        sort3(nums, vec[1] + 1, high);
    }
}
vector<int> partition3(vector<int> &nums, int low, int high){
    vector<int> vec;
    int temp;
    int ans = nums[high];
    int left = low - 1;
    int right = high;
    while(low < right){
        if(nums[low] < ans){
            temp = nums[++left];
            nums[left] = nums[low];
            nums[low++] = temp;
        }
        else if(nums[low] > ans){
            temp = nums[--right];
            nums[right] = nums[low];
            nums[low] = temp;
        }
        else
        {
            /* code */
            low++;
        }
       
    }
    nums[high] = nums[right];
    nums[right] = ans;
    vec.push_back(left+1);
    vec.push_back(right);
    return vec;
}
=======
>>>>>>> 339fd3625b998ad160d2f34da2a2708db4a7a66a
int main(){
    vector<int> vec;
    for(int i = 0; i < 500; i++){
        vec.push_back(rand() % 500);
    }
    // print(vec);
    // cout<<"经典快排："<<endl;
    // quicksort1(vec);
    // print(vec);
    cout<<"改进的快速排序："<<endl;
    quicksort2(vec);
    print(vec);
    system("pause");
    return 0;
}