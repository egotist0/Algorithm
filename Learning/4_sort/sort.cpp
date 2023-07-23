#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

/****************************************************************************************/
// 选择排序
void selectSort(){
    for(int i =1;i<=n;i++){ //进行n趟操作
        int k = i;
        for(int j=i;j<=n;j++){
            if(a[k]>a[j]){
                k=j;
            }
        }
        //交换
        int tmp=a[i];
        a[i]=a[k];
        a[k]=tmp;
    }
}

/****************************************************************************************/
//插入排序
void insertSort(){
    for(int i=2;i<=n;i++){
        int tmp=a[i],j=i;
        while(j>1 && tmp<a[j-1]){  //从后往前查找插入位置
            a[j]=a[j-1];
            j--;
        }
        a[j]=tmp;
    }
}

/****************************************************************************************/
//归并排序
const int maxn=100;
//归并函数（运用了）
void merge(int a[],int l1,int r1,int l2,int r2){
    int i=l1,j=l2; //让i指向数组1的左边界，j为2的左边界
    int tmp[maxn],index=0;
    while (i<=r1 && j<=r2)
    {
        if(a[i]<=a[j]){
            tmp[index++]=a[i++];
        }else{
            tmp[index++]=a[j++];
        }
    }

    while(i<r1){
        tmp[index++]=a[i++];
    }
     while(j<r2){
        tmp[index++]=a[j++];
    }

    for(i=0;i<index;i++){  //将合并后的数组赋值回数组A
        a[l1+i]=tmp[i];
    }

}

//递归实现
void mergeSort(int a[],int left,int right){
    if(left<right){  //只要左边界小于右边界
        int mid=(left+right)/2;
        mergeSort(a,left,mid); //递归，左子区间归并排序
        mergeSort(a,mid,right); //递归，右子区间归并排序
        merge(a,left,mid,mid+1,right); //合并左右子区间
    }
}

//非递归实现
void mergeSort(int a[]){
    //step为组内元素个数
    for(int step=2;step<=n;step*=2){
        for(int i=1;i<=n;i+=step){ //分组（从1开始排序）
            int mid=i+step/2-1;  //左区间右边界（-1是考虑到初始元素也算入个数）
            if(mid+1<=n){
                merge(a,i,mid,mid+1,min(i+step-1,n));
            }
        }
    }
}

//也可以直接调用sort函数(其实已经没太大必要了，只是这样可以输出每一趟归并后的结果)
void mergeSort(int a[]){
    for(int step=2;step/2<=n;step*=2){  //边界设计是因为最后一趟时，step=n
        for(int i=1;i<=n;i+=step){
            sort(a+i,a+min(i+step,n+1)); //sort函数的边界是末尾元素的后面那个位置
        }
    }
}


/****************************************************************************************/
//快排见另一文件