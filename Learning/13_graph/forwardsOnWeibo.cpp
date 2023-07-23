#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn=1010;

struct node{
    int id;
    int layer;
};

vector<node> adj[maxn]; //邻接表
bool inq[maxn]={false}; //判断是否已经加入过队列

int bfs(int s,int l){ //l为层数上限
    int num=0; //转发数设为0
    queue<node> q;
    node start;
    start.id=s;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        int u=tmp.id;
        for(int i=0;i<adj[u].size();i++){
            node next=adj[u][i];
            next.layer=tmp.layer+1;
            if(inq[next.id]==false && next.layer<=l){
                q.push(next);
                inq[next.id]=true;
                num++;
            }
        }
    }
    return num;
}

int main(){
    node user;
    int n,l,num,idFollow;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++){
        user.id=i;
        scanf("%d",&num); //该用户关注的人数
        for(int j=0;j<num;j++){
            scanf("%d",&idFollow);
            adj[idFollow].push_back(user);
        }
    }

    int numQuery,s;
    scanf("%d",&numQuery);
    for(int i=0;i<numQuery;i++){
        memset(inq,false,sizeof(inq));
        scanf("%d",&s);
        int numForward=bfs(s,l);
        printf("%d\n",numForward);
    }

    return 0;
}