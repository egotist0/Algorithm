//AOV和AOE可以互相转换
//最长路径长度=不拖延的最短时间
//关键路径=最长路径

/*
最长路径
1.对于一个没有正环的图（源点可达的正环）
2.将所有边的边权都乘以-1，变为相反数，然后用BF算法或者SPFA算法求最短路径，然后将结果取反
3.如果存在正环，则最长路径是不存在的
4.存在正环的情况下，只是求最长简单路径（每个顶点最多经过一次），那么存在路径，但没法通过BF等算法求出，为NP-Hard问题
5.一般情况下最长路径就是最长简单路径
*/

//AOE本质上为DAG，此处给出求关键路劲（最长路径）的解法（同样适用于DAG）

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


struct node
{
    int v;
    int w;
};

//拓扑序列求ve[](每个事件的最早发生时间)
const int maxv=1000;
vector<node> g[maxv]; //邻接表
int n,m,in[maxv]; //点数，边数，入度
int ve[maxv],vl[maxv];
stack<int> top;

bool topologicalSort(){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        top.push(u); //加入拓扑序列
        for(int i=0;i<g[i].size();i++){
            int v=g[u][i].v;
            in[v]--; //入度减1
            if(in[v]==0){
                q.push(v);
            }

            //用ve[u]来更新u的所有后继结点
            if(ve[u]+g[u][i].w>ve[v]){
                ve[v]=ve[u]+g[u][i].w;
            }
        }
    }

    if(top.size()==n) return true;
    else return false;
}

//拓扑序列求vl[](每个事件的最晚发生时间)
//因为需要从后继结点往前求，与ve[]的要求正好相反（要求在访问某个节点时它的后继结点都已经访问完毕）
//需要逆拓扑排序（可以直接颠倒在topo排序中得到的序列）
void re_topo(){
    fill(vl,vl+n,ve[n-1]); //vl数组初始化，初始值为终点的ve值！！！

    //直接使用topOrder出栈即为逆拓扑序列
    while(!top.empty()){
        int u=top.top();
        top.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v; //u的后继结点v
            //用u的所有后继结点的vl值更新vl[u]
            if(vl[v]-g[u][i].w<vl[u]){
                vl[u]=vl[v]+g[u][i].w;
            }
        }
    }
}

//以上可以总结为，先求点，再求边
//最早（拓扑序）:ve[j]=max{ve[i]+length[i->j]}
//最晚（逆拓扑序）:ve[i]=min{vj[i]-length[i->j]}

//e[i->j]=ve[i]
//l[i->j]=vl[j]-length[i->j]

//e=l 即为关键活动

//关键路径（不是DAG返回-1，否则返回关键路径长度）
int CriticalPath(){
    memset(ve,0,sizeof(ve)); //初始化ve数组
    if(topologicalSort()==false){
        retun -1; //不是DAG
    }
    fill(vl,vl+n,ve[n-1]); //vl数组初始化，初始值为汇点的ve值（此时默认汇点为n-1！！！！）
    //直接使用topOrder出栈即为逆拓扑序列
    while(!top.empty()){
        int u=top.top();
        top.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v; //u的后继结点v
            //用u的所有后继结点的vl值更新vl[u]
            if(vl[v]-g[u][i].w<vl[u]){
                vl[u]=vl[v]+g[u][i].w;
            }
        }
    }

    //遍历邻接表的所有边，计算活动开始的最早时间e和最晚时间l
    for(int u=0;u<n;u++){
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].v,w=g[u][i].w;
            //活动（边）开始的最早和最晚时间
            int e=ve[u],l=vl[v]-w;
            if(e==l){
                printf("%d->%d",u,v);  //最早等于最晚，为关键活动
            }
        }
    }

    return ve[n-1]; //返回关键路径长度（此处可根据汇点做修改）
}

//如果事先不知道汇点，则取ve[]数组的最大值为汇点
int maxLength=0;
for(int i=0;i<n;i++){
    if(ve[i]>maxLength){
        maxLength=ve[i];
    }
}
fill(vl,vl+n,maxLength); //注意vl数组用ve[]最大值初始化！！！！！（终点的ve值）
//如果有多条关键路径，需要把关键活动记载下来
//新建一个邻接表，将u->v加入邻接表，最后生成的表就是所有关键路径形成的图，可以用(DFS!!)获取所有关键路径