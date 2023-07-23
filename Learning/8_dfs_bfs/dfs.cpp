//dfs常用于给定一个序列，枚举这个序列的所有子序列
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

const int maxn=30;
int n,v,maxValue = 0; //物品件数n，背包容量v，最大价值
int w[maxn],c[maxn]; //每件物品的重量和价值

//dfs和index为当前处理的物品编号
void dfs(int index,int sumW,int sumC){
    if(index==n){ //已完成对n件物品的选择
        if(sumW<=v && sumC>maxValue){
            maxValue=sumC;
        }
        return;
    }

    //岔路口
    dfs(index+1,sumW,sumC); //选择
    dfs(index+1,sumW+w[index],sumC+c[index]); //不选择
}

int main(){
    scanf("%d%d",&n,&v);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&c[i]);
    }
    dfs(0,0,0);
    printf("%d\n",maxValue);
    return 0;
}

//此时代码复杂度较大，为o（2^n），可以提前加入限制条件进行剪枝
void dfs(int index,int sumW,int sumC){
    if(index==n){ //已完成对n件物品的选择
        return;
    }
    dfs(index+1,sumW+w[index],sumC+c[index]); //不选择
    //岔路口
    if (sumW+c[index] <=v){
        if (sumC+c[index]>maxValue)
        {
            maxValue=sumC+c[index];
        }
        dfs(index+1,sumW,sumC); //选择
    }
}

/*********************************************************************************/

//给定n个整数，从中选择k个数,要求和为x，且平方和最大的方案
int n,k,x,max=-1,a[maxn];
//tmp存储临时方案，ans存放平方和最大的方案
vector<int> tmp,ans;
void DFS(int index,int nowK,int sum,int squ){
    if(nowK == k && sum == x){ //找到的k个数和为x
        if(squ>max){
            max=squ;
            ans=tmp; //更新方案
        }
        return;
    }

    //已经处理完n个数，或超过了k个数，或者和超过x，返回
    if(index==n || nowK >k || sum > x) return;

    //岔路

    //选择index号数
    tmp.push_back(a[index]);
    DFS(index+1,nowK+1,sum+a[index],squ+a[index]*a[index]);
    tmp.pop_back;  //!!!!!!!!!!!!!!一定要注意，分支结束时要将其从tmp中去除，这样就不会影响后面不选择的分支

    //不选择
    DFS(index+1,nowK,sum,squ)；
}