//寻找两个字符串的最大公共子序列

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100;
char a[N],b[N];
int dp[N][N]; //表示a的第i位和b的第j位前的lcs

int main(){
    int n;
    gets(a+1); //从下标为1开始读
    gets(b+1);

    int lena=strlen(a+1); //同样计算距离的起始位置要往后推一个
    int lenb=strlen(b+1);

    //边界
    for(int i=1;i<=lena;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=lenb;i++){
        dp[0][j]=0;
    }

    //状态转移
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    printf("%d\n",dp[lena][lenb]);
    return 0;
}