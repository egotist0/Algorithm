#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

/****************************************************************************************/
// ѡ������
void selectSort(){
    for(int i =1;i<=n;i++){ //����n�˲���
        int k = i;
        for(int j=i;j<=n;j++){
            if(a[k]>a[j]){
                k=j;
            }
        }
        //����
        int tmp=a[i];
        a[i]=a[k];
        a[k]=tmp;
    }
}

/****************************************************************************************/
//��������
void insertSort(){
    for(int i=2;i<=n;i++){
        int tmp=a[i],j=i;
        while(j>1 && tmp<a[j-1]){  //�Ӻ���ǰ���Ҳ���λ��
            a[j]=a[j-1];
            j--;
        }
        a[j]=tmp;
    }
}

/****************************************************************************************/
//�鲢����
const int maxn=100;
//�鲢�����������ˣ�
void merge(int a[],int l1,int r1,int l2,int r2){
    int i=l1,j=l2; //��iָ������1����߽磬jΪ2����߽�
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

    for(i=0;i<index;i++){  //���ϲ�������鸳ֵ������A
        a[l1+i]=tmp[i];
    }

}

//�ݹ�ʵ��
void mergeSort(int a[],int left,int right){
    if(left<right){  //ֻҪ��߽�С���ұ߽�
        int mid=(left+right)/2;
        mergeSort(a,left,mid); //�ݹ飬��������鲢����
        mergeSort(a,mid,right); //�ݹ飬��������鲢����
        merge(a,left,mid,mid+1,right); //�ϲ�����������
    }
}

//�ǵݹ�ʵ��
void mergeSort(int a[]){
    //stepΪ����Ԫ�ظ���
    for(int step=2;step<=n;step*=2){
        for(int i=1;i<=n;i+=step){ //���飨��1��ʼ����
            int mid=i+step/2-1;  //�������ұ߽磨-1�ǿ��ǵ���ʼԪ��Ҳ���������
            if(mid+1<=n){
                merge(a,i,mid,mid+1,min(i+step-1,n));
            }
        }
    }
}

//Ҳ����ֱ�ӵ���sort����(��ʵ�Ѿ�û̫���Ҫ�ˣ�ֻ�������������ÿһ�˹鲢��Ľ��)
void mergeSort(int a[]){
    for(int step=2;step/2<=n;step*=2){  //�߽��������Ϊ���һ��ʱ��step=n
        for(int i=1;i<=n;i+=step){
            sort(a+i,a+min(i+step,n+1)); //sort�����ı߽���ĩβԪ�صĺ����Ǹ�λ��
        }
    }
}


/****************************************************************************************/
//���ż���һ�ļ�