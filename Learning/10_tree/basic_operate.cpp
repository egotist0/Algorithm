#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


//树一般做题时常用静态写法，需要事先开一个大小不低于节点上线个数的结点数组
struct node{
    int data; //数据域
    int child[maxn]; //指针域，存放所有子节点的下标
}Node[maxn]; //结点数组

//这种情况下占用空间过多，使用vector（根据长度自动调整）
struct node{
    int data; //数据域
    int layer;
    vector<int> child; //指针域，存放所有子节点的下标
}Node[maxn]; //结点数组

//创建结点(与静态二叉树类似)
int index=0;
int newNode(int v){
    Node[index].data=v;
    Node[index].child.clear(); //清空子节点
    return index++;
}

//先根遍历
void preorder(int root){
    printf("%d\n",Node[root].data); //访问当前结点
    for(int i=0;i<Node[root].child.size();i++){
        preorder(Node[root].child[i]);  //递归访问结点root的所有子结点
        //递归边界？
    }
}

//层序遍历
void Layerorder(int root){
    queue<int> q; //注意队列存指针或者位置更好
    Node[root].layer=0; //这里记录根结点层号为0（依据题意定）
    q.push(root);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        printf(Node[front].data);
        for(int i=0;i<Node[front].child.size();i++){
            int child=Node[front].child[i];
            Node[child].layer=Node[front].layer+1;
            q.push(child);
        }
    }
}