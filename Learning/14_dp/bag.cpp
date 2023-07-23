//dp[i][v]表示前i件物品 恰好 装进容量为v的背包中所能获得的最大价值
//dp[i][v]=max{dp[i-1][v],dp[i-1][v-w[i]]+c[i]}

//dp[i][v]只与dp[i-1][]有关
//边界dp[0][v]=0

//不使用滚动数组
for(int i=1;i<=n;i++){
    for(int v=w[i];v<=V;v++){
        dp[i][v]=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i]);
    }
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100; //物品最大件数
const int maxv=1000; //v的上限

int w[maxn],c[maxn],dp[maxv];

//使用滚动数组的版本i从1到n遍历，v（背包容量）要从V到w[i]反向遍历
//因为计算dp[i][v]需要用到左上方（左侧的数据），所以需要从右（右下）遍历，这样可以用到左侧（左上的内容）

int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }

    //边界(dp[0][v]=0)
    for(int i=0;i<=v;i++){
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){ //从上到下
        for(int j=v;j>=w[i];j--){ //从右到左
            //状态转移方程
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }

    //寻找dp[0...v]中最大的即为答案
    int max=0;
    for(int i=0;i<=v;i++){
        if(dp[i]>max){
            max=dp[i];
        }
    }

    printf("%d\n",max);
    return 0;
}

//完全背包问题（每个物品数量不设限）
//对于状态转移方程
/*
1.不放第i件物品的情况和01背包一致
2.放第件物品并不会转移到dp[i-1][v-w[i]]，因为数量可以任意，还可以继续放这第i件物品直到v-w[i]无法保持大于等于0未知
dp[i][v]=max[dp[i-1][v],dp[i][v-w[i]]+c[i]]  (1<=i<=n; w[i]<=v<=V)
*/

//滚动数组实现
/*
与01背包区别
01背包必须要你想枚举
完全背包的v是正向枚举的
是否正向逆向主要四看选择第i个物品时的迭代式
01背包需要的是上一层
完全背包是本层（所以左边需要存在数据）
*/
for(int i=1;i<=n;i++){
    for(int v=w[i];v<=V;v++){
        dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
    }
}