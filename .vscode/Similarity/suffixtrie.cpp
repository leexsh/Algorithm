#include <iostream>
#include<map>
#include<string>
#include<iterator>
#include<queue>
using namespace std;

int num_node=0;

//两个字符串的比较
int compare(string a,string b)
{
    int i;
    for(i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
            break;
    }
    return i;
}

//后缀树的节点
class suffix_node
{
public:
    map<char,suffix_node*> children;
    string str;
    int id;
    suffix_node(){}

    void insertstring(string s)
    {
        suffix_node* child=NULL;
        suffix_node* nod=NULL;
     if(children.find(s[0])==children.end())
     {
        child=new suffix_node();
        child->str=s;
        child->id=num_node;
        num_node++;
        children[s[0]]=child;
     }
     else
     {
       child=children[s[0]];
       int i;
       string st,st1;
       char ch;
       if(child->str.length()<=s.length())
       i=compare(child->str,s);
       else
        i=compare(s,child->str);
       while(i>=child->str.length()&&i<s.length())
        {
            nod=child;
          s=s.substr(i,s.length()-i);
       if(nod->children.find(s[0])==nod->children.end())
       {
           suffix_node* n=new suffix_node();
           n->id=num_node;
           num_node++;
           n->str=s;
           nod->children[s[0]]=n;
           return ;
       }
          child=child->children[s[0]];
          i=compare(s,child->str);
        }
       if(i<s.length()&&i<child->str.length())
       {
       st=s.substr(0,i);
       suffix_node* node=new suffix_node();
       node->id=num_node;
       num_node++;
       node->str=st;
       suffix_node* node1=new suffix_node();
       node1->id=num_node;
       num_node++;
       node1->str=s.substr(i,s.length()-i);
       child->str=child->str.substr(i,child->str.length()-i);
       st1=child->str;
         node->children[st1[0]]=child;
         st1=node1->str;
         node->children[st1[0]]=node1;
         st1=node->str;
         if(nod==NULL)
            children[st1[0]]=node;
         else
            nod->children[st1[0]]=node;
       }
     }
   }
};

class suffix_tree
{

public:
    suffix_node* root;
    suffix_tree(string s)
    {
        string str;
        root=new suffix_node();
        root->id=num_node;
        num_node++;
        for(int i=0;i<s.length();i++)
        {
            str=s.substr(i);
           root->insertstring(str);
        }
    }
    ~suffix_tree(){}
};

int find_str(string T,string s)          //寻找字符串S是否在字符串T中
{
    suffix_tree tree(T);
      if(T.length()<s.length())
    {
        cout<<"字符串S不在字符串T中"<<endl;
        return 0;
    }
    string str=s;
    suffix_node* node=NULL;
        int i;
       node=tree.root->children[s[0]];
       while(str.length()!=0)
       {
           if(str.length()<=node->str.length())
           {
              i=compare(str,node->str);
              if(i>=str.length())
              {
                cout<<"字符串S在字符串T中"<<endl;
                return 1;
              }
              else
              {
                cout<<"字符串S不在字符串T中"<<endl;
                 return 0;
              }
           }
           else
           {
              i=compare(node->str,str);
              if(i>=node->str.length())
              {
                str=str.substr(i,str.length()-i);
                node=node->children[str[0]];
              }
              else
              {
                cout<<"字符串S不在字符串T中"<<endl;
                 return 0;
              }
           }
       }
}

int num_leaf(suffix_tree tree,suffix_node* node)
{
    int num=0,number=0;
    suffix_node* node1=NULL;
    map<char,suffix_node*>::iterator its;
    for(its=node->children.begin();its!=node->children.end();its++)
        num++;
        if(num==0)
        {
            return 1;
        }
        else
        {
             for(its=node->children.begin();its!=node->children.end();its++)
             {
                 number+=num_leaf(tree,its->second);
             }
        }
        return number;
}

int num_echo(string T,string s)        //指定字符串S在字符串T中的重复次数
{
   suffix_tree tree(T);
   suffix_node* node=NULL;
   int i,num=0;
   i=find_str(T,s);
   if(i==0)
    return 0;
   node=tree.root->children[s[0]];
      while(s.length()>node->str.length())
      {
          s=s.substr(node->str.length(),s.length()-node->str.length());
          node=node->children[s[0]];
      }

      return num_leaf(tree,node);
}

int is_leaf(suffix_node* node,suffix_tree tree)
{
   map<char,suffix_node*>::iterator its;
   int num=0;
   for(its=node->children.begin();its!=node->children.end();its++)
        num++;
   if(num>0)
    return 0;
   else
    return 1;
}

//求最长回文串
string longest_echo_string(string T)
{
    map<char,suffix_node*>::iterator its;
    queue<suffix_node*> q;
    string long_str;
    int max=0;
    suffix_node* node=NULL;
    suffix_tree tree(T);
    q.push(tree.root);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        if(max<node->str.length())
        {
            max=node->str.length();
            long_str=node->str;
        }
        for(its=node->children.begin();its!=node->children.end();its++)
        {
            if(is_leaf(its->second,tree)==0)
            {
                (its->second)->str+=node->str;
                q.push(its->second);
            }
        }
    }
    return long_str;
}
int has_$(suffix_node *node,suffix_tree tree)
{
    map<char,suffix_node*>::iterator its;
    string s;
    int num1=1;int num2=1;int i;
    for(its=node->children.begin();its!=node->children.end();++its)
    {
        s+=its->second->str;
    }
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='y')
            num1--;
        if(s[i]=='z')
            num2--;
        if(num1<=0&&num2<=0)
        break;
    }
    if(i>=s.length())
        return 0;
    else
        return 1;
}

//最长公共子串
string longest_common(string t,string s)
{
    suffix_node* node=NULL;
    map<char,suffix_node*>::iterator its;
    queue<suffix_node*> q;
    string long_str,str;
    int max=0;int num;
    t+="y";s+="z";
    str=t+s;
    suffix_tree tree(str);
    q.push(tree.root);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        num=0;
        for(its=node->children.begin();its!=node->children.end();its++)
        {
            if(is_leaf(its->second,tree)==0)
                num++;
        }

        if(num==0&&has_$(node,tree))
        {
         if(max<node->str.length())
         {
            max=node->str.length();
            long_str=node->str;
         }
        }
        for(its=node->children.begin();its!=node->children.end();its++)
        {
            if(is_leaf(its->second,tree)==0)
            {
                (its->second)->str=node->str+(its->second)->str;
                q.push(its->second);
            }
        }
    }
    return long_str;
}
int main()
{
    string T,s,str;
    int a;
    //cin>>T;
    //cin>>s;
//    a=find_str(T,s);
//    a=num_echo(T,s);
//    cout<<a<<endl;
//    str=longest_echo_string(T);
    str=longest_common("keks","kehkr");
    cout<<str<<endl;
//   suffix_tree tree(T);
//   suffix_node* node=(tree.root)->children['e'];
//   suffix_node* node1=node->children['k'];
//   cout<<node1->children['a']->str<<endl;
    system("pause");
    return 0;
}