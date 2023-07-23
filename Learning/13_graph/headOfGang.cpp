#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn=2010; //总人数
const int inf=100000000; //无穷大

map<int,string> intToString; //编号->姓名
map<string,int> stringToInt; //姓名->编号
map<string,int> gang; //head->人数

int g[maxn][maxn]={0},weight[maxn]={0}; //邻接矩阵，点权矩阵
int n,k,num; //边数，阈值，总人数
bool vis[maxn]={false};

void dfs(int now,int& head,int& sum,int& value){ //需修改的值要用引用传递
    sum++;
    vis[now]=true;
    if(weight[now]>weight[head]){
        head=now; //如果当前成员的点权大于头目，更新头目
    }
    for(int i=0;i<num;i++){
        if(g[now][i]>0){ //如果能够访问到i
            value+=g[now][i]; //连通块总边权增加该边边权
            g[now][i]=g[i][now]=0; //删除该边，防止回头
            if(vis[i]==false){ //没有访问，则递归访问
                dfs(i,head,sum,value);
            }
        }
    }
}

void dfsTrave(){
    for(int i=0;i<num;i++){
        if(vis[i]==false){
            int head=i,value=0,sum=0;
            dfs(i,head,sum,value); //遍历i所在的连通块
            if(num>2 && value>k){
                gang[intToString[head]]=sum;
            }
        }
    }
}

//change函数返回姓名str对应的编号
int change(string str){
    if(stringToInt.find(str)!=stringToInt.end()){ //如果str已经出现过
        return stringToInt[str]; //返回编号
    } else{
        stringToInt[str]=num;
        intToString[num]=str; //相互对应
        return num++; //总人数加1
    }
}

int main(){
    int w;
    string str1,str2;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>str1>>str2>>w; //输入边的两个端点和边权
        int id1=change(str1);
        int id2=change(str2);
        weight[id1]+=w;
        weight[id2]+=w;
        g[id1][id2]+=w;
        g[id2][id1]+=w;
    }
    dfsTrave();
    cout<<gang.size()<<endl;
    map<string,int>::iterator it;
    for(it=gang.begin();it!=gang.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}