#include"bits/stdc++.h"
using namespace std;
// ���ŵ�Ӧ��

// ����һ
// ����һ������arr����һ����num�����С�ڵ���num����������
// �����ߣ�����num��������������ұߡ�
// Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)



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





// ������������������⣩
// ����һ������arr����һ����num�����С��num�������������
// ��ߣ�����num��������������м䣬����num��������������ұߡ�
// Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)

// �����������������it
// ����һ���������飬����һ��ֵK�����ֵ��ԭ������һ�����ڣ�Ҫ���������С��K��Ԫ�طŵ��������ߣ�
// ��K��Ԫ�طŵ�������ұߣ�����K��Ԫ�طŵ�������м䣬
// ���շ���һ���������飬����ֻ������ֵ���ֱ��ǵ���K�����鲿�ֵ����������±�ֵ��
// ���磬�������飺[2, 3, 1, 9, 7, 6, 1, 4, 5]������һ��ֵ4��
// ��ô��������ԭ������ܵ�һ������ǣ�[2, 3, 1, 1, 4, 9, 7, 6, 5]����Ҫע����ǣ�
// С��4�Ĳ��ֲ���Ҫ���򣬴���4�Ĳ���Ҳ����Ҫ���򣬷��ص���4���ֵ����������±꣬��[4, 4]
void partition2(vector<int> &arr, int num){
    int low = 0 - 1;
    int high = arr.size();
    int i = 0;
    int temp;
    while(i < high){
        //С��num�� ��lowָ��ĺ�һ������
        if(arr[i] < num){
            temp = arr[i];
            arr[i++] = arr[++low];
            arr[low] = temp;
        }
        // ����num�ĸ�high��ǰһ������
        else if(arr[i] > num){
            temp = arr[--high];
            arr[high] = arr[i];
            arr[i] = temp;
        }
        // ����num�Ĳ���
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