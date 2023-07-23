#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod=1000000007; //hash模数
const ll P=10000019; //进制数
const ll maxn=200010; //字符串最长长度

ll p[maxn],a[maxn],ra[maxn];

//初始化P[数组]
void init(){
    p[0]=1;
    for(int i=1;i<maxn;i++){
        p[i]=(p[i-1]*P)%mod;
    }
}

//计算字符串不同位置hash
void calH(ll h[],string& str){
    h[0]=str[0];
    for(int i=1;i<str.length();i++){
        h[i]=(h[i-1]*P+str[i])%mod;
    }
}

//计算子串hash
ll calSubstring(ll h[],int i,int j){ //起始位置
    if(i==0) return h[j];
    return ((h[j]-h[i-1]*p[j-i+1])%mod+mod)%mod;
}

//分奇偶考虑
//isEven表示是否为奇数
//对称点为i，字符串长len，在[l,r]里二分查找回文半径
int binarySearch(int l,int r,int len,int i,int isEven){
    while(l<r){ //当出现l==r结束（l到r是范围）
        int mid=(1+r)/2;
        //分为左半子串和右半子串
        int h1l=i-mid+isEven,h1r=i;
        int h2l=len-1-(i+mid),h2r=i;
        int hashl=calSubstring(a,h1l,h1r);
        int hashr=calSubstring(b,h2l,h2r);
        if(hashl!=hashr) r=mid; //hash值不相等，说明回文半径>mid
        else l=mid+1;
    }
    return l-1; //返回最大回文半径
}

int main(){
    init();
    string str;
    getline(cin,str);
    calH(a,str);
    reverse(str.begin(),str.end()); //反转字符串
    calH(b,str);
    int ans=0;
    //奇回文
    for(int i=0;i<str.length();i++){ //枚举对称中心
        //二分上界为分界点i的左右长度的较小值加1
        int maxlen=min(i,(int)str.length()-1-i)+1;
        int k=binarySearch(0,maxlen,str.length(),i,0);
        ans=max(ans,k*2+1);
    }
    //偶回文
    for(int i=0;i<str.length();i++){
        //二分上界为分界点i的左右长度的较小值加1(左侧长度为i+1)
        int maxlen=min(i+1,(int)str.length()-1-i)+1;
        int k=binarySearch(0,maxlen,str.length(),i,1);
        ans=max(ans,k*2);
    }

    printf("%d\n",ans);
    return 0;
}