//通过子串哈希值进行求解
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll mod=1000000007; //计算hash值时的模数
const ll P=10000019; //hash值计算的进制数
const ll maxn=1010; //字符串最大长度

ll p[maxn],a[maxn]={0},b[maxn]={0}; //p存放p^i%mod,ab分别存放两个字符串的哈希值
vector<pair<int,int> >pr1,pr2; //pr1，pr2分别存放str1和2的所有子串的哈希值

//init初始化p
void init(int len){
    p[0]=1;
    for(int i=1;i<=len;i++){
        p[i]=(p[i-1]*P)%mod; //计算子串哈希值需要
    }
}

//计算字符串str的hash值
void calH(ll h[],string &str){
    h[0]=str[0]; //h[0]单独处理
    for(int i=1;i<str.length();i++){
        h[i]=(h[i-1]*P+str[i])%mod;
    }
}

//计算子串哈希
int calSubstring(ll h[],int i,int j){
    if(i==0) return h[j];
    return ((h[j]-h[i-1]*p[j-i+1])%mod+mod)%mod;
}

//计算所有子串hash，并将<子串hash，子串长度>存入pr
void calSub(ll h[],int len,vector<pair<int,int> >&pr){
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            int hashValue=calSubstring(h,i,j);
            pr.push_back(make_pair(hashValue,j-i+1));
        }
    }
}

//计算pr1和pr2中相同的hash值
int getMax(){
    int ans=0;
    for(int i=0;i<pr1.size();i++){
        for(int j=0;j<pr2.size();j++){
            if(pr1[i].first==pr2[j].first){
                ans=max(ans,pr1[i].second);
            }
        }
    }
    return ans;
}

int main(){
    string str1,str2;
    getline(cin,str2);
    getline(cin,str1);
    //初始化p数组
    init(max(str1.length(),str2.length()));
    //计算str1和2的hash值
    calH(a,str1);
    calH(b,str2);
    calSub(a,str1.length(),pr1); //计算所有子串hash
    calSub(b,str2.length(),pr2);
    printf("ans=%d\n",getMax());
    return 0;
}