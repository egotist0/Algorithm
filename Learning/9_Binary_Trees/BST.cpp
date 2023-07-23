#include <cstdio>

struct node{
    int data;
    int layer; //层次，方便用于层序遍历
    node* lchild;
    node* rchild;
};

//新建结点
node* newNode(int v){
    node* Node = new node; //!!!申请一个node型变量的地址空间
    Node->data=v;
    Node->lchild=Node->rchild=NULL;
    return Node; //返回新建结点地址
}

//查找
void search(node* root,int x){
    if(root==NULL){
        printf("search failed\n");
        return;
    }


    if(x==root->data){
        printf("%d\n",root->data);
    }else if(x<root->data){
        search(root->lchild,x);
    }else{
        search(root->rchild,x);
    }
}

//插入（查找失败的位置就是插入的位置）
//root要加引用（调整了树结构）
void insert(node* root,int x){
    if(root==NULL){ //空树，查找失败，插入位置
        root=newNode(x);
        return;
    }
    if(x==root->data){
        return; //已经存在，直接返回
    }else if(x<root->data){
        insert(root->lchild,x);
    }else{
        insert(root->rchild,x);
    }
}

//建立（插入n个结点的过程）
node* create(int data[],int n){
    node* root=NULL; //注意是设该结点为空值！！！（与插入的边界条件相对应）
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}

//删除（比删除结点小的最大节点，或者大的最小结点，即前驱与后继）
//前驱寻找
node* findMax(node* root){
    while(root->rchild!=NULL){
        root=root->rchild;
    }
    return root;
}

//后继寻找
node* findMin(node* root){
    while(root->lchild!=NULL){
        root=root->lchild;
    }
    return root;
}

void deleteNode(node* &root,int x){
    if(root==NULL){
        return;
    }
    if(root->data==x){
        if(root->lchild==NULL && root->rchild==NULL){
            root=NULL; //叶子节点直接删除，把root地址设为NULL，父结点就引用不到了
        }else if(root->lchild!=NULL){
            node* pre=findMax(root->lchild); //寻找root的前驱
            root->data=pre->data; //前驱覆盖root
            deleteNode(root->lchild,pre->data); //左子树中删除结点pre
        }else{
            node* next=findMin(root->rchild);
            root->data=next->data;
            deleteNode(root->rchild,next->data);
        }
    }
    else if(root->data>x){
        deleteNode(root->lchild,x); //在左子树删除x
    } else{
        deleteNode(root->rchild,x); //在右子树删除x
    }
}