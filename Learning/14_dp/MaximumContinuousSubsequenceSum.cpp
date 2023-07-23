//dp要尽量设计无后效性的状态和状态转移方程

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000;
int dp[maxn],a[maxn]; //a[]存放序列，dp[i]存放以a[i]结尾的连续序列最大值

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=a[0]; //边界
    for(int i=1;i<n;i++){
        dp[i]=max(a[i],dp[i-1]+a[i]); //状态转移方程
    }
    int k=0;
    for(int i=1;i<n;i++){
        if(dp[i]>dp[k]){
            k=i; //找到最大值
        }
    }
    printf("%d\n",dp[k]);
    return 0;
}