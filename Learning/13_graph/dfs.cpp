#include <cstdio>
#include <vector>
using namespace std;

//一个连同块只需要一次dfs

const int maxv=1000; //最大顶点数
const int inf=1000000000000; //inf设为一个很大的数

//邻接矩阵版
int n,g[maxv][maxv]; //n为顶点数，maxv为最大顶点数
bool vis[maxv]={false}; //判断是否访问过

void dfs(int x,int depth){ //对某个结点的dfs访问，depth为深度
    vis[x]=true; //设为已访问过
    //此处可对x进行一些操作
    for(int v=0;v<n;v++){
        if(vis[v]==false && g[x][v]!=inf){ //如果u所能到达的该分支结点未被访问过，并且边权可达
            dfs(v,depth+1); //访问，同时深度加1
        }
    }
}

void dfsTrave(){ //遍历图g
    for(int u=0;u<n;u++){
        if(vis[u]==false){
            dfs(u,1); //访问结点u及其所在的连通块，1表示初始为1层
        }
    }
}

//邻接表版
vector<int> adj[maxv];
int n;
bool vis[maxv]={false}; //判断是否访问过

void dfs(int x,int depth){
    vis[x]=true;
    for(int i=0;i<adj[x].size();i++){
        int v=adj[x][i];
        if(vis[v]==false){
            dfs(v,depth+1);
        }
    }
}

void dfsTrave(){
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            dfs(i,1);
        }
    }
}