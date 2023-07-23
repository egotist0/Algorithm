//该算法适用于边权都为非负数的情况，负数情况下可能会出错

/*
题目常考方式（增加第二标尺）
1.最短路径的数量
2.增加点权
3.增加第二边权

这种情况下只要新增一个数组来存放新增的边权或者点权或者最短路径条数
然后在修改d[v]的步骤修改算法即可！！！！！！！！！！！！！！！！！
其他部分无需改动
*/

#include <cstdio>
#include <vector>
using namespace std;

const int mxav=1000; //最大顶点数
const int inf=1000000000; //inf设为一个很大的树（10的九次方）

//邻接矩阵实现
int n,g[mxav][mxav]; //n为顶点数
int d[mxav]; //起点到各点的最短路径
bool vis[maxv]={false}; //判断是否已被访问
int pre[maxv]; //pre[v]表示从起点到顶点v的路径上v的前一个顶点（新添加），用于记录最短路径

void dijkstra(int s){ //s为起点
    fill(d,d+mxav,inf); //将d数组都赋值为inf（慎用memset（仅用于赋值为0或-1））d[u]+adj[u][v].dis

    for(int i=0;i<n;i++) pre[i]=i; //初始状态将每个点的前驱设为自身（新添加）

    d[s]=0; //起点到自身的距离为0
    for(int i=0;i<n;i++){ //循环n次
        int u=-1,min=inf; //u使d[u]最小，min存放最小的d[u]
        for(int j=0;j<n;i++){ //找到未访问结点中d[]最小的
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }
        //找不到小于inf的d[u]，说明剩下的顶点和起点s不连通，结束访问
        if(u=-1) return;

        vis[u]=true; //标记u为已访问
        for(int v=0;v<n;v++){
            //此时找到了最近的结点，通过该结点的出边更新最短距离
            if(vis[v]==false && g[u][v]!=inf && d[u]+g[u][v]<d[v]){
                d[v]=d[u]+g[u][v];
                pre[v]=u; //记录有距离更新的结点的前驱结点(新添加)
            }
        }
    }
}

void dfs(int s,int v){ //根据pre信息利用递归求两点间路径（从重点往上推）
    if(v==s){ //如果当前已经到达起点s，则输出起点并返回
        printf("%d\n",s);
        return;
    }
    dfs(s,pre[v]); //递归访问v的前驱结点
    printf("%d\n",v); //从最深处return回来后，输出每一层的结点（最后顺序是从起点到终点的顺序）
}

//临接表
struct node
{
    int v,dis; //v为边的目标顶点，dis为边权
};
vector<node> adj[maxv]; //图g，adj[u]存放了从顶点u出发能到达的所有顶点
int n; //顶点数
int d[maxv]; //到各店的最短路径
bool vis[maxv]={false}; //判断是否已访问


void dijkstra(int s){
    fill(d,d+mxav,inf); //最短距离全部赋值为无穷大
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }

        if(u=-1) return;

        vis[u]=true; //标记为已访问要放在后面，不然在上一步就找不到自身作为最近结点

        //此处开始和邻接矩阵不同
        for(int j=0;j<adj[u].size();j++){ //通过邻接表直接获得新加入结点能到达的临边
            int v=adj[u][j].v;
            if(vis[v]==false && d[u]+adj[u][v].dis<d[v]){ //未访问且可以是路径更优
                d[v]=d[u]+adj[u][v].dis;
            }
        }
    }
}



//！！！！！！！！！！！！！！！！！！1  dji+dfs形成通解(将所有路径信息都先求出来再根据题意使用dfs)

//1.记录所有的最短路径
vector<int> pre[maxv];
void dji_dfs(int s){
    fill(d,d+maxv,inf);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<min){
                u=j;
                min=d[j];
            }
        }

        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false && g[u][v]!=inf){
                if(d[u]+g[u][v]<d[v]){
                    d[v]=d[u]+g[u][v];
                    pre[v].clear(); //存在更优路径则直接优化（清空）已处在的前驱节点
                    pre[v].push_back(u);
                } else if(d[u]+g[u][v]==d[v]){
                    pre[v].push_back(u); //相等就直接压入
                }
            }
        }
    }
}

//2.遍历所有最短路径，寻找使第二标尺最优的方案
int opt; //第二标尺最优值
vector<int> path,tmpPath;

//反向查找
void dfs(int v){ //v为当前访问结点
    //递归边界
    if(v==s){ //如果到达了叶子节点（路径起点）
        tmpPath.push_back(v);
        int value; //临时存放第二标尺的值
        /*
        //边权之和
        int value=0;
        for(int i=tmpPath.size()-1;i> 0;i--){
            //当前结点和下一个结点
            int id=tmpPath[i],idNext=tmpPath[i-1];
            value+=v[id][idNext];
        }

        //点权之和
        int value=0;
        for(int i=tmpPath.size()-1;i>=0;i--){
            //当前结点和下一个结点
            int id=tmpPath[i];
            value+=w[id];
        }
        */
        if(value优于opt){
            opt=value;
            path=tmpPath;
        }
        tmpPath.pop_back(); //这条到叶子的路径访问完了，要去掉最后一个做其他路经查找！！！
        return;
    }

    //递归式
    tmpPath.push_back(v); //先压入
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]); //递归v的前驱结点
    }
    tmpPath.pop_back(); //遍历完所有前驱结点，将当前结点删除
}
