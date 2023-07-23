#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int data;
    int layer; //层次，方便用于层序遍历
    node* lchild;
    node* rchild;
};

//二叉树在建树前根节点不存在。其地址一般设为NULL
node* root = NULL;

//新建结点
node* newNode(int v){
    node* Node = new node; //!!!申请一个node型变量的地址空间
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node; //返回新建结点地址
}

//查找节点（递归）,修改节点
void search(node* root,int x,int newdata){
    if(root == NULL) return; //空树，死胡同，递归边界
    if(root->data==x) root->data=newdata;
    search(root->lchild,x,newdata); //递归左子树
    search(root->rchild,x,newdata); //递右左子树
}

//插入（结点插入位置是二叉树查找失败的位置）
//!!!!!!!!!!!!!根节点指针root要使用  引用   ，不然无法做修改会插入不成功
//如果函数中需要新建结点，即对二叉树的结构作出修改，就需要加引用；如果知识修改当前结点的内容就不需要引用
void insert(node* &root,int x){
    if(root==NULL){ //空树，查找失败，插入位置
        root=newNode(x);
        return;
    }

    if(二叉树性质决定，插在左子树){
        insert(root->lchild,x); //左子树递归
    } else{
        insert(root->rchild,x); //右子树递归
    }
}

//二叉树的创建
//将数据存储在数组中逐个插入
node* create(int data[],int n){
    node*root=NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

//遍历（左子树永远先于右子树访问）,边界为子树为空
//先序遍历
void preorder(node* root){
    if(root==NULL)return; //到达空树，递归边界

    printf("%d\n",&root->data);

    preorder(root->lchild);
    preorder(root->rchild);
}

//中序遍历
void inorder(node* root){
    if(root==NULL)return; //到达空树，递归边界

    inorder(root->lchild);

    printf("%d\n",&root->data);

    inorder(root->rchild);
}

//后序遍历
void postorder(node* root){
    if(root==NULL)return; //到达空树，递归边界

    postorder(root->lchild);

    postorder(root->rchild);

    printf("%d\n",&root->data);
}

//层序遍历（BFS实现）
void bfs(node* root){
    queue<node*> q; //！！！！！！！！！！注意存的是地址不是结点，如果直接存原数据的话就无法对其进行修改（队列存的是一个副本，无法同时修改）
    root->layer=1; //设置根节点层数为1
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        if(now->lchild!=NULL){
            now->lchild->layer=now->layer+1; //更新层号
            q.push(now->lchild);
        }
        if(now->rchild!=NULL){
            now->rchild->layer=now->layer+1; //更新层号
            q.push(now->lchild);
        }
    }
}

//已知先序和中序，重建二叉树
node* create(int preL,int preR,int inL,int inR){
    if(preL>preR){ //如果先序序列长度小于等于0，则返回
        return NULL;
    }

    node* root=new node;
    root->data=pre[preL];
    int k; //外部定义，方便存储位置
    for(k=inL;k<=inR;k++){
        if(in[k]==pre[preL]){
            break; //查找位置
        }
    }

    int numl=k-inL; //左子树的节点个数
    //左子树的先序区间为[preL+1，preL+numl]，中序区间为[inl，k-1]
    //左子树的先序区间为[preL+numl，prer]，中序区间为[k+1,inr]

    //！！！！！！！！！返回左子树的根结点地址，赋值给root的左指针
    root->lchild=create(preL+1,preL+numl,inL,k-1);
    root->rchild=create(preL+numl,preR,k+1,inR);

    //返回根结点地址
    return root;
}
