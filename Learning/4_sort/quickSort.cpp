#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <algorithm>

using namespace std;


int partition(int a[],int l,int r){
    // int p=rand()%r;
    // int p=0;
    // int tmp=a[l];
    // a[l]=a[p];
    // a[p]=tmp;
    int tmp=a[l];
    while(l<r){
        while (l<r && a[r]>tmp)
        {
            r--;
        }
        a[l]=a[r];
        while(l<r && a[l]<=tmp){  //Ҫ����ע�����=�ŵ�λ�ã���ΪҪ��tmpȡ�ȣ������ĸ���λ�ø�tmp���Ǹ�ȡ��
            l++;
        }
        a[r]=a[l];
    }
    a[l]=tmp;  //ע����һ��
    return l;
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int pos=partition(a,l,r);
        partition(a,l,pos-1); //pos���λ�þ͹̶�������
        partition(a,pos+1,r);
    }
}


int main(){
    int n;
    srand((unsigned)time(NULL));
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}