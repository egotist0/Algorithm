//输入n个字符串（只有小写），求其种不同的个数

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int mod=1000000007; //1e9+7
const int p=10000019; //1e7+19
//此时能保证字符串哈希冲突该流程很小

vector<int> ans;

//字符串hash
long long hashFunc(string str){
    long long h=0; //使用long long避免溢出
    for(int i=0;i<str.length();i++){
        h=(h*p+str[i]-'a')%mod;
    }
    return h;
}

int main(){
    string str;
    while(getline(cin,str),str!="#"){ //输入str直到#停止
        long long id=hashFunc(str);
        ans.push_back(id);
    }
    sort(ans.begin(),ans.end()); //排序
    int count=0;
    for(int i=0;i<ans.size();i++){
        if(i==0 || ans[i]!=ans[i-1]){
            count++; //统计不同的数的个数
        }
    }
    cout<<count<<endl;
    return 0;
}