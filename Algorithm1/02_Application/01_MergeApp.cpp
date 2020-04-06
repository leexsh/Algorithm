#include"bits/stdc++.h"
using namespace std;
/*
    归并排序的应用： 小和问题和逆序对
    求小和问题：在随机元素，随机数组大小的数组中，找出左边比右边元素小的所有元素之和。
    例如：数组[4,2,5,1,7,3,6] 第一个元素4比2大，不算小和，5比4和2都大，那就是4+2=6；
    1比4和2和5都小，不算小和；7比前面的都大，那就是上次小和6+4+2+5+1=18；
    然后3前面比2和1大，那就是18+2+1=21；最后6比4、2、5、1、3都大，
    结果就是21+4+2+5+1+3=36。那么最后的结果就是36。

    解法：使用归并排序来进行求和，在归并的时候把数组分成左右两个，
    在归并排序进行左右两个数组drc进行合并排序的时候进行计算。
    如果左边数组元素N，小于右边数组元素M，那么从右边数组右指针P到右边数组最后R就有(R-P+1)个N，依次累计相加，最后求出最小和。

*/

// 小和发生器  时间复杂度O(n^2)
int getMin(vector<int> nums){
    int sum = 0;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                sum += nums[j];
        }
    }
    return sum;
}
void print(vector<int> v){
    for(auto i : v){
        cout<<i<<" ";
    }
}
// 采用归并方法 时间复杂度O(NlogN)
int Sort1(vector<int>&, int, int);
int Merge1(vector<int>&, int, int, int);
int SmallSum(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
    return Sort1(nums, 0, nums.size() - 1);
}
// 左区间的小和 + 右区间的小和 + 左右区间归并产生的小和
int Sort1(vector<int> &nums, int low, int high){
    if(low == high)
        return 0;
    int mid = low + ((high - low)>>1);
    return Sort1(nums, low, mid) + Sort1(nums, mid + 1, high) + Merge1(nums, low, mid, high); 
}
// 归并产生小和的过程
int Merge1(vector<int> &nums, int low, int mid, int high){
    int p1 = low, p2 = mid + 1;
    vector<int> help(high - low + 1);
    int ans = 0;
    int i = 0;
    while(p1 <= mid &&p2 <= high){
        ans += nums[p1] < nums[p2] ? (high - p2 + 1)*nums[p1] : 0;
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }

    while(p1 <= mid){
        help[i++] = nums[p1++];
    }
    while(p2 <= high){
        help[i++] = nums[p2++];
    }

    for(int i = 0; i < help.size(); i++){
        nums[low + i] = help[i];
    }
    return ans;
}

// 小和问题的测试
void test01(){
   vector<int> v;

    // 随机发生器
    for(int i = 0; i < 500; i++){
        v.push_back(rand() % 100);
    }
  
    int n = getMin(v);
    int k = SmallSum(v);
    cout<<endl<<"逆序对发生器结果:"<<n<<endl;
    cout<<"归并排序逆序对结果:"<<k<<endl;
}


/*
    逆序对的问题
        在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
    逆序对：
        数组[4,2,5,1,7,3,6]，如果要求逆序对，所谓逆序对就是[4,2],[4,1],[5,1].....,  那么就是左边比右边大，
        那么有多少个逆序对就是,中间位置mid减去左指针下坐标P1+1个逆序对，也就是(mid-P1+1)个逆序对，
        把逆序对相加进行返回就是共有多少逆序对。

*/
// 逆序对发生器  时间复杂度O(n^2)
int getPairs(vector<int> nums){
    int sum = 0;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                sum++;
        }
    }
    return sum;
}
// 小和归并方法
int Sort2(vector<int>& nums, int low, int high);
int Merge2(vector<int>& nums, int low, int mid, int high);

int ReversePairs(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
    return Sort2(nums, 0, nums.size() - 1);

}
int Sort2(vector<int>& nums, int low, int high){
    if(low == high)
        return 0;
    int mid = low + (high - low >> 1);
    return Sort2(nums, low, mid) + Sort2(nums, mid + 1, high) + Merge2(nums, low, mid, high); 
}
int Merge2(vector<int>& nums, int low, int mid, int high){
    int p1 = low, p2 = mid + 1;
    int count = 0;
    int i = 0;
    vector<int> help(high - low + 1);
    while(p1 <= mid && p2 <= high)
    {
        count += nums[p1] < nums[p2] ? high - p2 + 1 : 0;
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] :nums[p2++];
    }
    while(p1 <= mid){
        help[i++] = nums[p1++];
    }
    while(p2 <= high){
        help[i++] = nums[p2++];
    }
    for(i = 0; i < help.size(); i++){
        nums[low + i] = help[i];
    }
    return count;

}

// 逆序对个数问题测试
void test02(){
      vector<int> v;

    // 随机发生器
    for(int i = 0; i < 500; i++){
        v.push_back(rand() % 100);
    }
    int c = getPairs(v);
    int count = ReversePairs(v);
    cout<<"逆序对发生器产生小和个数为 "<<c<<"个"<<endl;
    cout<<"归并方法产生的逆序对有 "<<count<<"个"<<endl;
}

int main(){
    
    //小和问题
    test01();
    cout<<"------------------------"<<endl;
    // 逆序对问题
    test02();
    system("pause");
    return 0;
}
