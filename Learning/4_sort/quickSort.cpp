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
        while(l<r && a[l]<=tmp){  //要极其注意这个=号的位置，因为要与tmp取等，所以哪个的位置给tmp就那个取等
            l++;
        }
        a[r]=a[l];
    }
    a[l]=tmp;  //注意这一步
    return l;
}

void quickSort(int a[],int l,int r){
    if(l<r){
        int pos=partition(a,l,r);
        partition(a,l,pos-1); //pos这个位置就固定下来了
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