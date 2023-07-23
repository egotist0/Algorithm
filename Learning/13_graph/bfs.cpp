#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

//一个连同块只需要一次bfs

const int maxv=1000; //最大顶点数

struct node
{
    int x; //顶点编号
    int layer;
};

//邻接矩阵版
int n,g[maxv][maxv]; //n为顶点数，maxv为最大顶点数
bool inq[maxv]={false}; //判断是否访问过

void bfs(int x){ //对某个结点的bfs访问
    queue<int> q;
    q.push(x);
    inq[x]=true; //设为已访问过
    //此处可对x进行一些操作
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(inq[i]==false && g[x][i]!=0){
                q.push(i);
                inq[i]=true;
            }
        }
    }
}

void bfsTrave(){ //遍历图g
    for(int u=0;u<n;u++){
        if(inq[u]==false){
            bfs(u); //访问结点u及其所在的连通块
        }
    }
}

//邻接表版
vector<int> adj[maxv];
int n;
bool inq[maxv]={false}; //判断是否访问过

void bfs(int x){
    queue<int> q;
    q.push(x);
    inq[x]=true;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            int v=adj[x][i];
            if(inq[v]==false){
                q.push(v);
                inq[v]=true;
            }
        }
    }
}

void bfsTrave(){
    for(int i=0;i<n;i++){
        if(inq[i]==false){
            bfs(i);
        }
    }
}

//考虑层数
vector<node> adj[maxv];
void bfs(int x){
    queue<node> q;
    node start;
    start.x=x;
    start.layer=0; //起始顶点层号设为0
    q.push(start);
    inq[start.v]=true;
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        int u=tmp.x;
        for(int i=0;i<adj[u].size();i++){
            node next=adj[u][i];
            next.layer=tmp.layer+1; //next层号加1
            if(inq[next.x]==false){
                q.push(next);
                inq[next.x]=true;
            }
        }
    }
}