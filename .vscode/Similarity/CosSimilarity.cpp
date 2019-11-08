#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    double cosineSimilarity(vector<int> A, vector<int> B) {
        int m = A.size();
        int count = 0 , count1 = 0 , count2 = 0;
        for (int i =0; i < m; i++) {
            count += A[i] * A[i];
            count1 += A[i] * B[i];
            count2 += B[i] * B[i];
        }
     
        return count1/(sqrt(count)*sqrt(count2));
    }
};

int main(){
    Solution s;
    vector<int> A;
    vector<int> B;
    cout<<"向量长度"<<endl;
    int n;
    cin>>n;
    int nValue;
    for(int i = 0; i < n; i++){
        cout<<"输入A的内容"<<endl;
        cin>>nValue;
        A.push_back(nValue);
    }
     for(int i = 0; i < n; i++){
        cout<<"输入B的内容"<<endl;
        cin>>nValue;
        B.push_back(nValue);
    }
    cout<<s.cosineSimilarity(A, B)<<endl;
    system("pause");
    return 0;
}