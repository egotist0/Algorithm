#include <cstdio>
#include <stdlib.h>
#include <vector>
using namespace std;

//邻接矩阵相较更占内存，一般适用于顶点数目不太大（一般不超过1000）的题目
//邻接表（可以用链表或者vector实现）
const int n=100;
vector<int> adj[n]; //每一个adj[i]为一个变长数组vector（可根据具体要求修改vector的类型）

struct Node{
    int v,w; //分别为终点和边权
    Node(){}
    Node(int _v,int _w) : v(_v),w(_w){} //构造函数(如果重新定义了构造函数，就不能不经初始化就定义结构体变量)
}

//添加操作
void insert(int i,int v,int w){
    adj[i].push_back(Node(v,w));
}