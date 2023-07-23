//常用于判断是否是DAG（有向无环图）
//如果要求存在多个入度为0的结点时，选择编号最小的结点，则可以把queue改为priority_queue，并保持堆顶段素为优先级队列中最小元素即可（set也可实现）

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

//读入图时就要记录好每个结点的入度

const int maxv=1000;
vector<int> g[maxv]; //邻接表
int n,m,in[maxv]; //点数，边数，入度

//拓扑排序
bool topologicalSort(){
    int num; //加入拓扑序列的顶点数
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i]==0){
            q.push(i); //将所有入度为0的顶点入队
        }
    }

    while(!q.empty()){
        int u=q.front();
        //printf("%d",u); 此处可以输出顶点u，作为拓扑序列的顶点
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i]; //u的后继结点v
            in[v]--;
            if(in[v]==0){
                q.push(v); //如果顶点v的入度减小至0，则入队
            }
        }
        g[u].clear(); //清空顶点u的所有出边（如无必要可不写）
        num++; //入队过的结点数量增加
    }
    if(num==n){
        return true; //加入拓扑序列的顶点数为n，说明为dag，拓扑排序成功
    }else{
        return false; //小于n，不为dag
    }
}