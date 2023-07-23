#include<cstdio>
#include <queue>

using namespace std;

const int maxn=100;
struct node{
    int x,y; //定义位置
}Node;

int n,m; //矩阵大小
int matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0}; //增量矩阵

bool judge(int x,int y){ //判断节点是否已经访问过
    if(x>=n || y>=m || x<0 ||y<0){ //越界返回false
        return false;
    }

    if(matrix[x][y]==0 || inq[x][y]==true){ //当前位置为0或者节点已入队，返回false
        return false;
    }

    return true;
}

//bfs函数访问节点所在的块，将对应的bool位置都设置为true
void bfs(int x,int y){
    queue<node> q;
    Node.x=x,Node.y=y; //定义当前节点位置
    q.push(Node);
    inq[x][y]=true;

    while (!q.empty())
    {
        node top = q.front(); //取出队首元素
        q.pop();
        for(int i=0;i<4;i++){
            int newX=top.x+x[i];
            int newY=top.y+y[i];
            if(judge(newX,newY)){ //如果新位置需要访问
                Node.x=newX,Node.y=newY;
                q.push(Node);
                inq[newX][newY]=true; //设置该位置已入过队
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            scanf("%d",&matrix[x][y]);
        }
    }

    int ans;  //存放块数
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            //如果元素为1且未入过队
            if(matrix[x][y]==1 && inq[x][y]==false){
                ans++;  //块数加1
                bfs(x,y); //访问整个块，同时将该块所有为1的相邻位置bool设为true
            }
        }
    }

    printf("%d",ans);
    return 0;
}