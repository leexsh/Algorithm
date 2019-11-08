#include<iostream>
#include<cmath>
using namespace std;
class Euclidean{
	public:
		Euclidean(int m, double arr1[],double arr2[]);
		//??
		void Calculate(double arr1[], double arr2[]);
		void Set(double arr1[],double arr2[]);
		double Get(){
			return Result;
		}
		~Euclidean(){}
	private:
		int n;
		double *a;
		double *b;
		double square;
		double Result;
};

Euclidean::Euclidean(int m, double arr1[], double arr2[]){
	n = m;
	Set(arr1,arr2);
	Calculate(a,b);
}
void Euclidean::Set(double arr1[],double arr2[]){
	a = arr1;
	b = arr2;
}
void Euclidean::Calculate(double a[], double b[]){
	square = 0;
	for(int i = 0; i < n; i++){
		square += (a[i] - b[i])*(a[i] - b[i]);
	}
	Result = sqrt(square / n);

}

int main(){
	int n;
    cout<<"Please input the dimensions n:";
    cin>>n; 
    double a[n];
    double b[n];
    cout<<"Input the "<<n<<" number for the dimendions of a1:";
       for(int i=0;i<n;i++)
           cin>>a[i];
    cout<<"Input the "<<n<<" number for the dimendions of b1:";
       for(int i=0;i<n;i++)
          cin>>b[i];
    Euclidean distance(n,a,b);
    cout<<"The distance is:"<<distance.Get()<<endl;
	system("pause");
	return 0;
}