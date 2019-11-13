#include"bits/stdc++.h"
using namespace std;
//��������

// �������
void sort1(vector<int>&, int, int);
int partition1(vector<int>&, int,int);

void quicksort1(vector<int> &nums){
    // ����Ϊ��
    if(nums.size() == 0){
        return;
    }
    // ����
    sort1(nums, 0, nums.size() - 1);
}
// ����
void sort1(vector<int> &nums, int low, int high){
    if(low < high){
        int num = partition1(nums, low, high);
        sort1(nums, low, num-1);
        sort1(nums, num+1,high);
    }
}
// �����ֿ��Ĺ���
int partition1(vector<int>&nums, int low, int high){
    // left�Ƿֽ���
    int left = low - 1;
    int ans = nums[high];
    int temp;
    while(low < high){
        // С�ڵ���left�Ķ�����left����� ����left�Ķ�����left���ұ�
        if(nums[low] <= ans){
            temp = nums[++left];
            nums[left] = nums[low];
            nums[low++] = temp;
        }
        else{
            low++;
        }
    }
    // ��high���ں��ʵ�λ��
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

//���������е�������
void swap(vector<int>&nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
//���ú��������ѡ�����һ�����Ľ��������������
void sort2(vector<int>&, int, int);
pair<int, int> partition2(vector<int>&, int,int);
void quicksort2(vector<int> &nums){
    if(nums.size() <= 1)
        return;
    sort2(nums, 0, nums.size() - 1);
}
void sort2(vector<int> &nums, int low, int high){
    if(low < high){
        // ����һ������������һ�������н���
        swap(nums, low + rand()%(high - low + 1), high);
        pair<int, int> p = partition2(nums, low, high);
        sort2(nums, low, p.first - 1);
        sort2(nums, p.second+1, high);
    }
}

pair<int, int> partition2(vector<int>&nums, int low,int high){
    // left����߶��Ǳ�ansС���� �ұ߶��ǵ���ans����
    int left = low - 1;
    // right����߶��ǵ���ans���� �ұ߶��Ǵ���ans����
    int right = high;
    int ans = nums[high];
    int temp;
    // ����Ĺ���
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
    // ��ans���ڵ��ڵ�ans�����һ��
    swap(nums, high, right);
    // ����һ��pair�� first�����һ������ans���� second�������һ������ans����
    pair<int, int> p(left+1, right);
    return p;
}
<<<<<<< HEAD
// ��pair��Ϊ���� ʵ����ͬ�ĸĽ����������
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
    // cout<<"������ţ�"<<endl;
    // quicksort1(vec);
    // print(vec);
    cout<<"�Ľ��Ŀ�������"<<endl;
    quicksort2(vec);
    print(vec);
    system("pause");
    return 0;
}