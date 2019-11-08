#include"bits/stdc++.h"
using namespace std;
/*
    �鲢�����Ӧ�ã� С������������
    ��С�����⣺�����Ԫ�أ���������С�������У��ҳ���߱��ұ�Ԫ��С������Ԫ��֮�͡�
    ���磺����[4,2,5,1,7,3,6] ��һ��Ԫ��4��2�󣬲���С�ͣ�5��4��2�����Ǿ���4+2=6��
    1��4��2��5��С������С�ͣ�7��ǰ��Ķ����Ǿ����ϴ�С��6+4+2+5+1=18��
    Ȼ��3ǰ���2��1���Ǿ���18+2+1=21�����6��4��2��5��1��3����
    �������21+4+2+5+1+3=36����ô���Ľ������36��

    �ⷨ��ʹ�ù鲢������������ͣ��ڹ鲢��ʱ�������ֳ�����������
    �ڹ鲢���������������������кϲ������ʱ����м��㡣
    ����������Ԫ��N��С���ұ�����Ԫ��M����ô���ұ�������ָ��P���ұ��������R����(R-P+1)��N�������ۼ���ӣ���������С�͡�

    ����ԣ�
    ���Ҫ������ԣ���ν����Ծ���[4,2],[4,1],[5,1].....,  ��ô������߱��ұߴ�
    ��ô�ж��ٸ�����Ծ���,�м�λ��mid��ȥ��ָ��������P1+1������ԣ�Ҳ����(mid-P1+1)������ԣ�
    ���������ӽ��з��ؾ��ǹ��ж�������ԡ�
*/

// ����Է�����  ʱ�临�Ӷ�O(n^2)
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
// ���ù鲢���� ʱ�临�Ӷ�O(NlogN)
int Sort(vector<int>&, int, int);
int Merge(vector<int>&, int, int, int);
int SmallSum(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
    return Sort(nums, 0, nums.size() - 1);
}
// �������С�� + �������С�� + ��������鲢������С��
int Sort(vector<int> &nums, int low, int high){
    if(low == high)
        return 0;
    int mid = low + ((high - low)>>1);
    return Sort(nums, low, mid) + Sort(nums, mid + 1, high) + Merge(nums, low, mid, high); 
}
// �鲢����С�͵Ĺ���
int Merge(vector<int> &nums, int low, int mid, int high){
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

int main(){
    vector<int> v;

    // ���������
    for(int i = 0; i < 500; i++){
        v.push_back(rand() % 100);
    }
  
    int n = getMin(v);
    int k = SmallSum(v);
    cout<<endl<<"����Է��������:"<<n<<endl;
    cout<<"�鲢��������Խ��:"<<k<<endl;
    system("pause");
    return 0;
}