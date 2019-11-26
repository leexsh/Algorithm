#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


// 冒泡排序 选择排序 插入排序 归并排序Ã°ÅÝÅÅÐò Ñ¡ÔñÅÅÐò ²åÐò

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}


// 1.Ã°ÅÝÅÅÐ 冒泡排序ò
void BubbleSort(vector<int> &nums){
    if(nums.size() < 2)
        return;
     int num = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = 0; j < nums.size() - 1 - i; ++j){
            if(nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j+1]);
                num++;
            }
        }
    }
    // cout<<"????"<<num<<endl;
}

// 2.Ñ¡ÔñÅÅÐò选择排序
void SelectSort(vector<int> &nums){
    if(nums.size() < 2)
        return;
    for(int i = 0; i < nums.size() - 1; ++i){
        int min = i;
        for(int j = i + 1; j < nums.size(); ++j){
            min = nums[min] > nums[j] ? j : min;
        }
        swap(nums[i], nums[min]);
    }
    // cout<<"????"<<num<<endl;
}

// 3.²åÈëÅÅÐò插入排序
void InsertSort(vector<int> &nums){
    if(nums.size() < 2)
        return;
    for(int i = 1; i < nums.size(); ++i){
        for(int j = i - 1; j >= 0 && nums[j] > nums[j+1]; --j){
            swap(nums[j], nums[j+ 1]);
        }
    }
    
}
void print(vector<int> nums){
    auto i = nums.begin();
    while(i != nums.end()){
        cout<<*i++<<" ";
    }
}

// 4.¹é²¢ÅÅÐò归并排序
void Sort(vector<int> &nums, int low, int high);
void Merge(vector<int> &nums, int low, int mid, int high);
void MergeSort(vector<int> &nums){
    if(nums.size() < 2){
        return;
    }
    Sort(nums, 0, nums.size() - 1);
}

void Sort(vector<int> &nums, int low, int high){
    if(low == high){
        return;
    }
    int mid = low + (high - low)/2;
    Sort(nums, low, mid);
    Sort(nums, mid+1, high);
    Merge(nums, low, mid, high);
}
void Merge(vector<int> &nums, int low, int mid, int high){
    int p1 = low, p2 = mid + 1;
    vector<int> help(high - low + 1);
    int i = 0;
    while(p1 <= mid && p2 <= high){
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }
    while(p1 <= mid){
        help[i++] = nums[p1++];
    }
    while(p2 <= high){
        help[i++] = nums[p2++];
    }
    i = 0;
    for(i; i < help.size(); i++){
        nums[low + i] = help[i];
    }
}
int main(){
    vector<int> vec;
    for(int i = 0; i < 500; i++){
        vec.push_back(rand() % 500);
    }
    // sort(vec.begin(), vec.end());
    cout<<"Ô­Ê¼Êý×é"<<endl;
    print(vec);
    // cout<<endl<<"Ã°ÅÝÅÅÐò:"<<endl;
    // BubbleSort(vec);
    // print(vec);
    // cout<<endl<<"Ñ¡ÔñÅÅÐò:"<<endl;
    // SelectSort(vec);
    // print(vec);
    // cout<<endl<<"²åÈëÅÅÐò:"<<endl;
    // InsertSort(vec);
    // print(vec);
    cout<<endl<<"¹é²¢ÅÅÐò:"<<endl;
    MergeSort(vec);
    print(vec);
    system("pause");
    return 0;
}

