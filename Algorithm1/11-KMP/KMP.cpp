#include "bits/stdc++.h"
using namespace std;
/*
KMP
    实现 strStr() 函数。
        给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
    示例 1:
        输入: haystack = "hello", needle = "ll"
        输出: 2
    示例 2:
        输入: haystack = "aaaaa", needle = "bba"
        输出: -1
    KMP算法 啊啊啊啊

*/

/*
思路：

 */

class Solution1 {
public:
    int strStr(string haystack, string needle) {
        if((haystack.empty() && !needle.empty())||haystack.size() < needle.size()){
            return -1;
        }
        if(haystack.empty() || needle.empty()){
            return 0;
        }
//        next数组
        vector<int> next = getNext(needle);
        int i1 = 0;
        int i2 = 0;
        while(i1 < haystack.size() && i2 < needle.size()){
//           都匹配 一起往后走
            if (haystack[i1] == needle[i2]){
                i1++, i2++;
            } else {
//                needle到了最开头 haystack无法与needle的开头配
                if (next[i2] == -1)
                {
                    i1++;
                } else{
//                    needle往前走
                    i2 = next[i2];
                }
            }
        }
        return i2 == needle.size() ? i1- i2 : -1;
    }

//    获取next数组
    vector<int> getNext(string &str)
    {
        if(str.size() == 1)
        {
            return vector<int>{-1};
        }
        vector<int> next(str.size(), 0);
//        str[0] 没有前缀
        next[0] = -1;
//        str[1]没有
        next[1] = 0;
        int i = 2;
        int coun = 0;
        while(i < str.size())
        {
//          str[i]的前一个元素与 最长前缀的后一个相等 加上
            if(str[coun] == str[i-1]){
                next[i++] = ++coun;
            } else if(coun > 0){
//                往前跳？
                coun = next[coun];
            } else
            {
                next[i++] = 0;
            }
        }
        return next;
    }
};
int main(){
    string s = "hello";
    string ss = "ll";
    Solution s1;
    int x = s1.strStr(s,ss);
//    cout<<x<<endl;
    system("pause");
    return 0;
}