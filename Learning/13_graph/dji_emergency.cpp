#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv=1000;
const int inf=1000000000;

int n,m,s,t;
int g[maxv][maxv],weight[maxv];
int d[maxv],w[maxv],num[maxv];
bool vis[maxv]={false};

void djikstra(int s){
    fill(d,d+maxv,inf);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    //初始化完成

    for(int i=0;i<n;i++){
        int u=-1,min=inf;
        for(int j=0;j<n;j++){
            if(vis[j]==false && d[j]<min){ //寻找距离已知结点最近的结点
                u=j;
                min=d[j];
            }
        }
        if(u=-1) return;
        vis[u]=true;
        for(int i=0;i<n;i++){
            if(vis[i]==false && g[u][i]!=inf){
                if(g[u][i]+d[u]<d[i]){
                    d[i]=g[u][i]+d[u];
                    w[i]=w[u]+weight[i];
                    num[i]=num[u];
                }else if(g[u][i]+d[u]==d[i]){
                    if(weight[i]+w[u]>w[i]){
                        w[i]=w[u]+weight[i];
                    }
                    num[i]+=num[u];
                }
            }
        }
    }
}


int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }

    int u,v;
    fill(g[0],g[0]+maxv*maxv,inf); //先初始化图！！！！！
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        scanf("%d",&g[u][v]);
        g[v][u]=g[u][v]; //无向图，所以要加上两条！！！
    }
    djikstra(s);
    printf("%d %d\n",num[t],w[t]);
    return 0;
}