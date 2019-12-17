#include "bits/stdc++.h"
using namespace std;
/*
    设计RandomPool结构
    【题目】 设计一种结构，在该结构中有如下三个功能：
        insert(key)：将某个key加入到该结构，做到不重复加入。
        delete(key)：将原本在结构中的某个key移除。 
        getRandom()：等概率随机返回结构中的任何一个key。
    【要求】 Insert、delete和getRandom方法的时间复杂度都是O(1)

*/
template<typename T>
class RandomPool{
public:
    RandomPool():size(0){}
    // RandomPool(){}
    // 插入
    void insert(T key){
        if(this->m1.count(key) == false){
            m1[key] = size;
            m2[size++] = key;
        }
    }
    // 删除
    // 用最后一个元素去填充删除的元素
    void deleteKey(T key){
        if(m1.count(key)){
            int delIndex = m1[key];
            int lastIndex = size--;
            T lastKey = m2[lastIndex];
            m1[lastKey] = delIndex;
            m2[delIndex] = lastKey;
            m1.erase(key);
            m2.erase(lastIndex); 
        }
    }
    // 随机返回
    T getRandom(){
        if(m1.empty()){
            return nullptr;
        }
        // 埋下随机数的种子
        srand(static_cast<unsigned>(time(0)));
        // 随机返回一个数
        int ran = static_cast<int>(rand() % size);
        cout<<"random : "<<ran<<endl;
        return m2[ran];
    }
    int getSize(){
        return this->size;
    }
private:
    map<T, int> m1;
    map<int, T> m2;
    int size;
};
int main(){
    RandomPool<string> r;
    r.insert("A");
    r.insert("B");
    r.insert("C");
    r.insert("D");
    cout<<"random "<<r.getRandom()<<endl;
    r.deleteKey(string("A"));
    cout<<"random "<<r.getRandom()<<endl;
    system("pause");
    return 0;
}