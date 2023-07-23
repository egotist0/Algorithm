//用于无向图中生成最小生成树
//思路与dijkstra类似
//o(n^2)尽量在顶点数量较少而边较多的情况下使用

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv=1000;
const int inf=1000000000;

//邻接矩阵
int n,g[maxv][maxv];
int d[maxv]; //结点到集合s的最短距离
bool vis[maxv]={false};

int prim(int s){ //s为树的根节点
    fill(d,d+maxv,inf); //fill函数初始化距离数组
    d[s]=0;
    int ans=0; //存放边权之和
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }

        if(u=-1) return -1;

        vis[u]=true;
        ans+=d[u]; //将与集合s距离最小的边加入最小生成树
        for(int v=0;v<n;v++){
            if(vis[v]==false && g[u][v]!=inf && g[u][v]<d[v]){
                d[v]=g[u][v]; //以新增加点为窗口更新它的邻接点的d
            }
        }
    }

    return ans;
}

//邻接表
struct node
{
    int v,dis;
};

vector<node> adj[maxv];
int n;
int d[maxv]; //结点到集合s的最短距离
bool vis[maxv]={false};

int prim(int s){ //s为树的根节点
    fill(d,d+maxv,inf); //fill函数初始化距离数组
    d[s]=0;
    int ans=0; //存放边权之和
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }

        if(u=-1) return -1;

        vis[u]=true;
        ans+=d[u]; //将与集合s距离最小的边加入最小生成树
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            int dis=adj[u][j].dis;
            if(vis[j]==false && dis<d[j]){
                d[j]=dis;
            }
        }
    }

    return ans;
}