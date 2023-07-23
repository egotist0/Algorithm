//n^3的复杂度，因此结点数量小于200
//使用邻接矩阵存储（这算法思想好暴力）
//全源最短路径

#include <cstdio>
#include <algorithm>
using namespace std;

const int inf=1000000000;
const int maxv=200; //最大顶点数
int n,m; //顶点数与边数
int dis[maxv][maxv]; //表示ij间的最短距离

void Floyd(){
    for(int k=0;k<n;k++){ //以k为中介点
        for(int i=0;i<n;i++){ //观察ij间距离是否会缩短
            for(int j=0;j<n;j++){
                if(dis[i][k]!=inf && dis[k][j]!=inf && dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j]; //中介点到两点都有边，且可以更新最短路径
                }
            }
        }
    }
}

int main(){
    int u,v,w;
    fill(dis[0],dis[0]+maxv*maxv,inf); //dis数组赋初值
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        dis[i][i]=0; //点到自身的距离都先初始化为0！！！！
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=w; //如果是有向图记得加上对称边
    }
    Floyd();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\n",dis[i][j]); //输出任意两点间最短距离
        }
    }
    return 0;
}