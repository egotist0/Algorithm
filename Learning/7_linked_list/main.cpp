#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

//创建链表（关键函数）
node* create(int a[],int n){
    node *p,*pre,*head; //定义p为当前节点，head为头结点，pre为一个临时指针
    head=new node; //注意实际的head和当前节点都需要进行内存分配
    head->next=NULL;
    pre = head;
    for (int i = 0; i < n; i++)
    {
        p = new node;
        p->data=a[i];
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
    return head;
}


//查找元素
int search(node* head,int x){
    int count=0;
    node* p=head->next;
    while(p!=NULL){
        if(p->data==x) count++;
        p=p->next;
    }
    return count;
}


//插入元素
void insert(node* head,int pos,int x){
    node* p=head;
    for(int i=1;i<pos;i++){
        p=p->next; //到插入前一个位置
    }
    node* q =new node;
    q->data=x;
    q->next=p->next;
    p->next=q;
}


//删除元素
void del(node* head,int x){
    node* p=head->next; //p从第一个节点开始枚举
    node* pre=head; //pre始终保持前驱节点的指针
    while(p!=NULL){
        if (p->data==x)
        {
            pre->next=p->next;
            delete(p);
            p=pre->next;
        }else{
            pre=p;
            p=p->next;
        }

    }
}


int main(){
    int a[5]={6,3,7,3,1};
    node *l=create(a,sizeof(a)/sizeof(int));
    insert(l,3,3);
    del(l,1);

    printf("%d\n\n",search(l,3));

    l=l->next;
    while(l!=NULL){
        printf("%d\n",l->data);
        l=l->next;
    }
    return 0;
}
