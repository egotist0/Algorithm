#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=100;
struct node
{
    int x,y; //位置
    int step; //起点到该位置的层数
}s,t,Node;

int n,m;
char maze[maxn][maxn]; //迷宫信息
bool inq[maxn][maxn]={false};
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0}; //增量矩阵

//检测位置（x，y）是否有效
bool test(int x,int y){
    if(x>=n || x< 0 || y>= m || y<0){
        return false;
    }

    if(maze[x][y]=='*'){
        return false;
    }

    if(inq[x][y]==true){
        return false;
    }

    return true; //有效位置
}

int bfs(){
    queue<node> q;
    q.push(s); //将起点s入队
    while(!q.empty()){
        node top = q.front(); //取出队首元素
        q.pop(); //队首出队
        if(top.x == t.x && top.y == t.y){ //如果为重点，直接返回最小步数
            return top.step;
        }

        for(int i=0;i<4;i++){ //循环4次，得到4个相邻位置
            int newX=top.x+x[i];
            int newY=top.y+y[i];
            if(test(newX,newY)){ //位置有效就入队
                Node.x=newX,Node.y=newY;
                Node.step=top.step+1;
                q.push(Node);
                inq[newX][newY]=true; //标记已入队
            }
        }
    }

    //无法到达终点则返回-1
    return -1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        getchar(); //!!!过滤掉每行后面的换行符
        for(int j=0;j<m;j++){
            maze[i][j]=getchar();
        }
        maze[i][m+1]='\0'; //字符数组的末尾要以'\o'结尾
    }

    scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
    s.step=0;
    printf("%d\n",bfs());
    return 0;
}