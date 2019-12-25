#include"bits/stdc++.h"
using namespace std;
/**
 *  ʵ��һ�ֹ�è���еĽṹ��Ҫ�����£� �û����Ե���add������cat���dog���
    ʵ����������У� �û����Ե���pollAll�����������������е�ʵ�����ս�����
    ���Ⱥ�˳�����ε����� �û����Ե���pollDog��������������dog���ʵ������
    �����е��Ⱥ�˳�����ε����� �û����Ե���pollCat��������������cat���ʵ
    �����ս����е��Ⱥ�˳�����ε����� �û����Ե���isEmpty����������������
    ����dog��cat��ʵ���� �û����Ե���isDogEmpty���������������Ƿ���dog
    ���ʵ���� �û����Ե���isCatEmpty���������������Ƿ���cat���ʵ����
 * 
*/
class Pet{
protected:
    string  s_type;
public:
    Pet(){}
    Pet(string s):s_type(s){}
    string getType(){
        return s_type;
    }
};
// ��
class Dog : public Pet
{
public:
    Dog():Pet("dog"){
    }
};
// è
class Cat : public Pet
{
public:
    Cat():Pet("cat"){
    }
};
class PetEnter{
public:
    Pet pet;
    long count;
    PetEnter(Pet p, long co):pet(p), count(co) {}
    string getType(){
        return pet.getType();
    }
    Pet getPet(){
        return pet;
    }
};
class DogCatQueue{
public:
    queue<PetEnter> dogQueue;
    queue<PetEnter> catQueue;
    long count;

    DogCatQueue():count(0){}

    void push(Pet &p){
        if(p.getType() == "dog"){
            PetEnter pe(p, count++);
            dogQueue.push(pe);
        }
        else if(p.getType() == "cat"){
            PetEnter pe(p, count++);
            catQueue.push(pe);
        }
    }
    Pet pop(){
        if(!dogQueue.empty() && !catQueue.empty()){
            if(dogQueue.front().count < catQueue.front().count){
                Pet p = dogQueue.front().getPet();
                dogQueue.pop();
                return p;
            }
            else{
                Pet p = catQueue.front().getPet();
                catQueue.pop();
                return p;
            }
        }
        else if(!dogQueue.empty() && catQueue.empty()){
             Pet p = dogQueue.front().getPet();
                dogQueue.pop();
                return p;
        }
        else if(dogQueue.empty() && !catQueue.empty()){
            Pet p = catQueue.front().getPet();
                catQueue.pop();
                return p;
        }
        else{
            cout<<"���ж���"<<endl;
            return (Pet)NULL;
        }
    }
    Pet popCat(){
        if(catQueue.empty()){
            cout<<"ûè"<<endl;
            return (Pet)NULL;
        }
        else{
            Pet p = catQueue.front().getPet();
            catQueue.pop();
            return p;
        }
    }
    Pet popDog(){
        if(dogQueue.empty()){
            cout<<"û��"<<endl;
            return (Pet)NULL;
        }
        else{
            Pet p = dogQueue.front().getPet();
            dogQueue.pop();
            return p;
        }
    }
    bool isEmpty(){
        return catQueue.empty() && dogQueue.empty();
    }
    bool isDogEmpty(){
        return dogQueue.empty();
    }
    bool isCatEmpty(){
        return catQueue.empty();
    }
};
int main(){
    DogCatQueue q;
    Dog d1;
    Cat c1;
    Dog d2;
    Cat c2;
    q.push(d1);
    q.push(d2);
    q.push(c1);
    q.push(c2);
    q.push(c1);
    q.push(d2);
    q.push(d1);
    q.push(c2);
    q.push(c1);
    q.push(d2);
    while(!q.isEmpty())
    {
        cout<<q.pop().getType()<<endl;
    }
    system("pause");
    return 0;
}