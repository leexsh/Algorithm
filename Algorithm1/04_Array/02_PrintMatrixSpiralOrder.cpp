#include"bits/stdc++.h"
using namespace std;
/*
תȦ��ӡ����
����Ŀ�� ����һ�����;���matrix���밴��תȦ�ķ�ʽ��ӡ����
���磺 1 2 3 4 5 6 7 8 9 10 11 12 13 14
15 16 ��ӡ���Ϊ��1��2��3��4��8��12��16��15��14��13��9��
5��6��7��11�� 10
��Ҫ�� ����ռ临�Ӷ�ΪO(1)��
*/
void printEdge(vector<vector<int>>&nums, int a, int b, int c, int d);
void printMatrixSpiralOrder(vector<vector<int>> &nums){
    if(nums.empty()){
        return;
    }
    int a = 0; 
    int b = 0;
    int c = nums.size()-1;
    int d = nums[0].size()-1;
    while(a <= c && b <= d){
        printEdge(nums, a++, b++, c--, d--);
    }
}
// �ȴ�ӡһȦ (a,b)�����Ͻǵĵ� (c,d)�����½ǵĵ�
void printEdge(vector<vector<int>>&nums, int a, int b, int c, int d){
    //������һ��
    if(a == c){
        for(int i = d; i <=d; i++){
            cout<<nums[a][i]<<" ";
        }
    }
    // ������һ��
    else if(b == d){
        for(int i = a; i <= c; i++){
            cout<<nums[i][b]<<" ";
        }
    }
    else{
        //��
        int heng = b;
        // ��
        int shu = a;
        // ��(a,b)��ӡ��(a,d)
        while(heng != d){
            cout<<nums[a][heng]<<" ";
            heng++;
        }
        // ��(a,d)��ӡ��(c,d)
        while(shu != c){
            cout<<nums[shu++][d]<<" ";
        }
        // cout<<"heng = "<<heng<<" shu = "<<shu<<endl;
        // ��(c,d)��ӡ��(c,b)
        while(heng != b){
            // cout<<nums[c][heng--]<<" ";
            cout<<nums[c][heng--]<<" ";
        }
        // // ��(c,b)��ӡ��(a,b)
        while(shu != a){
            cout<<nums[shu--][b]<<" ";
        }
    }
}

void test01(){
    vector<vector<int>> vec{{1,2,3,4,},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printMatrixSpiralOrder(vec);
}
int main(){
    test01();
    system("pause");
    return 0;
}