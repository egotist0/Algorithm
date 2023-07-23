#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//堆为完全二叉树，常用数组进行存储
const int maxn=100;
int heap[maxn],n=10; //n为元素个数

//向下调整操作（常用在建堆过程）
void downAdjust(int low,int high){ //low为欲调整的结点数组下标，high为堆的最后一个元素的数组下标
    int i=low,j=i*2; //i为需要调整的结点，j为左儿子
    while(j<=high){
        //如果右孩子存在，且值大于左孩子
        if(j+1<=high && heap[j]<heap[j+1]){
            j=j+1;
        }
        if(heap[j]>heap[i]){ //如果孩子大于父亲
            swap(heap[j],heap[i]);
            i=j; //交换记得把下标也换一下
            j=i*2;
        } else{
            break; //孩子权值小于父亲，调整结束
        }
    }
}

//建堆
void createHeap(){
    for(int i=n/2;i>=1;i--){
        downAdjust(i,n);
    }
}

//删除堆顶元素（只要拿最后一个元素覆盖堆顶元素，然后对根节点调整）
void deleteTop(){
    heap[1]=heap[n--]; //拿最后一个元素覆盖堆顶元素，同时元素个数减1
    downAdjust(1,n);
}

//插入元素（使用向上调整，与父亲比较，边界为满足情况或者堆顶）
void upAdjust(int low,int high){ //low一般设为1，high表示调整的数组下标
    int i=high,j=high/2; //父亲与孩子
    while(j>=low){ //父亲在范围内
        if(heap[j]<heap[i]){
            swap(heap[j],heap[i]);
            i=j;
            j=i/2;
        } else{
            break;
        }
    }
}

void insert(int x){
    heap[++n]=x; //加1然后赋给末值
    upAdjust(1,n);
}

//堆排序为了节省空间，倒着遍历数组
void heapSort(){
    createHeap(); //建堆
    for(int j=n;j>1;j--){
        swap(heap[j],heap[1]);
        downAdjust(1,j-1);
    }
}