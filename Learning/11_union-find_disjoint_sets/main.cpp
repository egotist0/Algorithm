#include <cstdio>
using namespace std;

const int maxn=100;
int father[maxn];


//并查集支持合并两个集合，判断两个元素是否在一个集合
//并查集内部不会产生环，每个都是一棵树
//使用首先需要初始化father数组

//initialize
void initialize(int i[],int n){ //初始时，每个元素都是一个独立的集合
    for(int i=0;i<n;i++){
        father[i]=i; //或者令father[i]为-1也可以
    }
}

//返回元素x所在集合的根节点
int findFather(int x){
    while(x!=father[x]){//如果不是根节点，持续循环
        x=father[x]; //获得父亲节点
    }
    return x;
}

//递归实现
int findFather(int x){
    if(father[x]==x) return x;
    else return findFather(father[x]);
}

//合并（将其中一个的根节点的父亲指向另一个集合的根结点）
//1.判断a，b是否是一个集合； 2.合并


void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB){
        father[faA]=faB; //不存在一个集合就合并
    }
}

//路径压缩加速查找根结点
int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    } //先找到根结点

    //路径压缩
    while(a!=father[a]){ //重走一遍，把路径上所有结点的父亲改成根结点
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}

//递归写法
int findFather(int x){
    if(father[x]==x) return x;
    else {
        int f=findFather(father[x]); //f存储根结点位置
        father[x]=f; //递归完后更新父结点信息
        return f;
    }
}