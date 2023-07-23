//该算法需要遍历所有的边，因此用邻接表会比较方便
/*
具体思路：
1.形成的最短路径树是一个不超过n层的树，其中根节点为s
2.每次循环就往下确定一层（通过上一层节点松弛的一定已经达到最短路径），因此所需要的次数最多为n-1
3.如果在某一轮松弛时发现所有的边都没有被松弛，那么说明数组d中所有距离已达最优，可以提前结束
*/

#include <cstdio>
#include <vector>
using namespace std;

const int maxv=1000;
const int inf=1000000000;

struct node{
    int v,dis; //v为邻接边的目标顶点，dis为边权
};

vector<node> adj[maxv];
int n; //顶点数
int d[maxv]; //最短路径长度

bool Bellman(int s){ //s位源点
    fill(d,d+maxv,inf); //同样先初始化最短距离的数组
    d[s]=0;

    //接下来求解数组d
    for(int i=0;i<n-1;i++){ //执行n-1轮操作（最短路径层数为n-1）
        for(int u=0;u<n;u++){ //每轮都遍历所有的边
            for(int j=0;j<adj[u].size();j++){
                int v=adj[u][j].v; //临接边的顶点
                int dis=adj[u][j].dis; //临接边的边权
                if(d[u]+dis<d[v]){
                    d[v]=d[u]+dis; //如果以u未终结点可以使d[v]更小，松弛该节点
                }
            }
        }
    }

    //接下来为判断负环的操作
    for(int u=0;u<n;u++){ //遍历所有的边
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v;
            int dis=adj[u][j].dis;
            if(d[u]+dis<d[v]){ //如果仍然存在可以被松弛的结点
                return false; //说明图中有从源点可达的负环
            }
        }
    }
    return true; //次数d中所有值都为最优
}