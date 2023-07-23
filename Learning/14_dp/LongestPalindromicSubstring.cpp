#include <cstdio>
#include <cstring>
const int maxn=1010;
char s[maxn];
int dp[maxn][maxn]; //表示i到j间的子串是否是回文序列

int main(){
    gets(s);
    int len=strlen(S),ans=1;
    memset(dp,0,sizeof(dp));

    //边界
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;  //初始化时注意更新当前最长回文子串长度
        }
    }

    //状态转移方程
    for(int l=3;l<=len;l++){ //枚举子串长度
        for(int i=0;i+l<=len;i++){ //枚举子串的起始结点
            if(s[i]==s[j] && dp[i+1][j-1]==1){ //如果两端结点相等，且i+1到j-1的序列也为回文序列
                dp[i][j]=1;
                ans=l; //更新最长回文子串长度
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}