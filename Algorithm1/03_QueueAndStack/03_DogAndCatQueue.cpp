#include"bits/stdc++.h"
using namespace std;
/**
 *  实现一种狗猫队列的结构，要求如下： 用户可以调用add方法将cat类或dog类的
    实例放入队列中； 用户可以调用pollAll方法，将队列中所有的实例按照进队列
    的先后顺序依次弹出； 用户可以调用pollDog方法，将队列中dog类的实例按照
    进队列的先后顺序依次弹出； 用户可以调用pollCat方法，将队列中cat类的实
    例按照进队列的先后顺序依次弹出； 用户可以调用isEmpty方法，检查队列中是
    否还有dog或cat的实例； 用户可以调用isDogEmpty方法，检查队列中是否有dog
    类的实例； 用户可以调用isCatEmpty方法，检查队列中是否有cat类的实例。
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
// 狗
class Dog : public Pet
{
public:
    Dog():Pet("dog"){
    }
};
// 猫
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
            cout<<"灭有动物"<<endl;
            return (Pet)NULL;
        }
    }
    Pet popCat(){
        if(catQueue.empty()){
            cout<<"没猫"<<endl;
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
            cout<<"没狗"<<endl;
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