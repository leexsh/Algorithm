#include"bits/stdc++.h"
using namespace std;
// 快排的应用

// 问题一
// 给定一个数组arr，和一个数num，请把小于等于num的数放在数
// 组的左边，大于num的数放在数组的右边。
// 要求额外空间复杂度O(1)，时间复杂度O(N)



void partition1(vector<int> &arr, int num){
    int cur = -1;
    int size = arr.size();
    int i = 0;
    while(i != size){
        if(arr[i] > num){
            i++;
        }
        else{
            int temp = arr[++cur];
            arr[cur] = arr[i];
            arr[i++] = temp;
        }
    }
}

void test01(){
    vector<int> vec{3,4,5,1,2};
    partition1(vec, 3);
    for(auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}





// 问题二（荷兰国旗问题）
// 给定一个数组arr，和一个数num，请把小于num的数放在数组的
// 左边，等于num的数放在数组的中间，大于num的数放在数组的右边。
// 要求额外空间复杂度O(1)，时间复杂度O(N)

// 荷兰国旗的问题描述it
// 给定一个整数数组，给定一个值K，这个值在原数组中一定存在，要求把数组中小于K的元素放到数组的左边，
// 于K的元素放到数组的右边，等于K的元素放到数组的中间，
// 最终返回一个整数数组，其中只有两个值，分别是等于K的数组部分的左右两个下标值。
// 例如，给定数组：[2, 3, 1, 9, 7, 6, 1, 4, 5]，给定一个值4，
// 那么经过处理原数组可能得一种情况是：[2, 3, 1, 1, 4, 9, 7, 6, 5]，需要注意的是，
// 小于4的部分不需要有序，大于4的部分也不需要有序，返回等于4部分的左右两个下标，即[4, 4]
void partition2(vector<int> &arr, int num){
    int low = 0 - 1;
    int high = arr.size();
    int i = 0;
    int temp;
    while(i < high){
        //小于num的 跟low指针的后一个交换
        if(arr[i] < num){
            temp = arr[i];
            arr[i++] = arr[++low];
            arr[low] = temp;
        }
        // 大于num的跟high的前一个交换
        else if(arr[i] > num){
            temp = arr[--high];
            arr[high] = arr[i];
            arr[i] = temp;
        }
        // 等于num的不变
        else{
            i++;
        }
    }
}
void test02(){
    vector<int> vec{3,4,5,1,2,3,3,3,3,6};
    partition2(vec, 3);
    for(auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){

    test01();
    test02();
    system("pause");
    return 0;
}