#include"bits/stdc++.h"
using namespace std;
/*
��ת�����ξ���
����Ŀ�� ����һ�����������ξ���matrix����Ѹþ��������
˳ʱ����ת90�ȵ����ӡ�
��Ҫ�� ����ռ临�Ӷ�ΪO(1)��
*/
void ratoteEdge(vector<vector<int>> &nums, int a, int b, int c, int d);
void print(vector<vector<int>> &nums){
    if(nums.empty()){
        return;
    }
    int a = 0;
    int b = 0;
    int c = nums.size() - 1;
    int d = nums[0].size() - 1;
    while(a<c){
        ratoteEdge(nums, a++, b++, c--, d--);
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[1].size(); j++){
            cout<<nums[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//(a,b)�����Ͻǵĵ� (c, d)�����½ǵĵ� ��(a,b)��ӡ��(c,d)Ȼ���ٴ�(c, d)��ӡ��(a,b)
void ratoteEdge(vector<vector<int>> &nums, int a, int b, int c, int d){
    int edge = d - b;
    int temp = 0;
    for(int i = 0; i != edge; i++){
        temp = nums[a][b+i];
        nums[a][b+i] = nums[c-i][b];
        nums[c-i][b] = nums[c][d-i];
        nums[c][d-i] = nums[a+i][d];
        nums[a+i][d] = temp;
    }
}
void test01(){
   vector<vector<int>> v{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   print(v); 
}
int main(){
    test01();
    system("pause");
    return 0;
}