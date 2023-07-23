#include <cstdio>
#include <vector>
using namespace std;

struct node
{
    int v,height; //v为结点数据域，height为当前子树高度（以当前结点为根结点的子树高度）
    node *lchild,*rchild;
};

//新建结点
node* newNode(int v){
    node* Node=new node;
    Node->v=v;
    Node->height=1; //结点高度初始为1
    Node->lchild=Node->rchild=NULL;
    return Node;
}

//获取节点root所在子树的高度
int getHeight(node* root){
    if(root==NULL){
        return 0; //空结点高度为0
    }
    return root->height;
}

//计算结点的平衡因子
int getBalance(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild); //左子树减右子树
}

//更新结点root的height
void updataHeight(node* root){
    //max(左孩子的height，右孩子的height)+1
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

//查找操作与二叉树是一样的
void search(node* root,int x){
    if(root==NULL){
        return;
    }
    if(root->v==x){
        printf("%d\n",root->v);
    }else if(x<root->v){
        search(root->lchild,x);
    }else{
        search(root->rchild,x);
    }
}

//插入
//左旋
//B的左子树成为A的右子树，A成为B的左子树，将根节点设为B
void l(node* &root){ //有修改就记得加引用
    node* tmp=root->rchild; //roo指向结点a，tmp指向结点B
    root->rchild=tmp->lchild;
    tmp->lchild=root;
    updataHeight(root);
    updataHeight(tmp);
    root=tmp;
}

//右旋
void r(node* &root){
    node* tmp=root->lchild;
    root->lchild=tmp->rchild;
    tmp->lchild=root;
    updataHeight(root);
    updataHeight(tmp);
    root=tmp;
}

//插入后需要从下往上判断结点是否失衡，因此需要在每个insert函数后更新当前字数的高度
void insert(node* &root,int v){ //记得引用
    if(root==NULL){ //空结点
        root=newNode(v);
        return;
    }
    if(v<root->v){
        insert(root->lchild,v); //插入
        updataHeight(root); //插入后更新树高
        if(getBalance(root)==2){ //失衡
            if(getBalance(root->lchild)==1){ //ll型号，右旋即可
                r(root);
            }else if(getBalance(root->lchild)==-1){ //lr型，先对左儿子左旋，再对根右旋
                l(root->lchild);
                r(root);
            }
        }
    }else{
        insert(root->rchild,v);
        updataHeight(root);
        if(getBalance(root)==-2){ //失衡
            if(getBalance(root->rchild)==-1){ //rr型号，左旋即可
                l(root);
            }else if(getBalance(root->rchild)==1){ //rl型，先对右儿子右旋，再对根左旋
                r(root->rchild);
                l(root);
            }
        }
    }
}

//AVL树的创建（依次插入n个结点
node* create(int a[],int n){
    node* root=NULL; //新建根结点root
    for(int i=0;i<n;i++){
        insert(root,a[i]);
    }
    return root;
}