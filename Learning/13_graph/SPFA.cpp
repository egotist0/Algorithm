//改进版的BF算法
//只有当某个顶点u的d[u]改变，从它出发的边的临结点d[v]才会改变
//可以使用一个队列
//如果某个定点的入队次数超过n-1，说明更存在源点可达的负环
//此处是bfs实现的

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int maxv=1000;
const int inf=1000000000;

struct node{
    int v,dis;
};

vector<node> adj[maxv];
int n,d[maxv],num[maxv]; //num存储了顶点的入队次数，方便判断负环
bool inq[maxv]; //顶点是否在队列中

bool SPFA(int s){
    //初始化
    memset(inq,false,sizeof(inq)); //不同于之前的算法
    memset(num,0,sizeof(num));
    fill(d,d+maxv,inf);

    //源点入队
    queue<int> q;
    q.push(s);
    inq[s]=true;
    num[s]++;
    d[s]=0;

    //主体
    while(!q.empty()){
        int u=q.front(); //取出队顶元素
        q.pop();
        inq[u]=false; //记得此时修改为出队
        //遍历所有该店出发的边
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            int dis=adj[u][j].dis;
            if(d[u]+dis<d[v]){
                d[v]=d[u]+dis; //进行松弛
                if(!inq[v]){ //如果不在队列中就入队
                    q.push(v);
                    inq[v]=true;
                    num[v]++;
                    if(num[v]>=n){
                        return false; //某个结点的入对次数超过n-1，则说明存在负环
                    }
                }
            }
        }
    }

    return true; //无可达负环
}