//用于无向图中生成最小生成树
//使用边贪心的思想（比prim思想更为简单）
//并查集实现
//适用于顶点数多，边数少的情况
//稠密图（边多），稀疏图（边少）

#include <cstdio>
#include<algorithm>
using namespace std;

const int maxe=1000;
int n; //借点数量

struct edge
{
    int u,v; //边的两个端点编号
    int w; //边权
}E[maxe];

bool cmp(edge a,edge b){ //比较两条边权值大小(sort函数)
    return a.w<b.w; //从小到大
}

int father[n]; //并查集数组
//路径压缩加速查找根结点
int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    } //先找到根结点

    //路径压缩
    while(a!=father[a]){ //重走一遍，把路径上所有结点的父亲改成根结点
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}

int kruskal(int n,int m){
    int ans=0,num=0; //ans为所求边权之和，num为生成树的边数
    for(int i=1;i<=n;i++){
        father[i]=i; //初始化并查集
    }
    sort(E,E+maxe,cmp); //边权从小到大排序
    for(int i=0;i<m;i++){ //枚举所有边
        int fau=findFather(E[i].u);
        int fav=findFather(E[i].v);
        if(fau=fav){ //不在同一个连通集中
            father[fau]=fav; //合并连通集
            ans+=E[i].w;
            num++;
            if(num==n-1) break; //如果边数等于总结点数减1，就结束算法
        }
    }

    if(num!=n-1) return -1; //边数小于n-1，说明不连通
    else return ans;
}