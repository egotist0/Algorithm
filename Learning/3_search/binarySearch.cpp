#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

/*
���ֲ��ң����÷ǵݹ�д��
*/
//a[]Ϊ�ϸ񵥵����У�leftΪ�½磬rightΪ�Ͻ�
int binarySearch(int a[],int left,int right,int x){
    int mid;
    while(left<=right){
        mid=(left+(right-left))/2;  //��ֹ���
        if(a[mid]==x) return mid;
        else if(a[mid]>x){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return -1; //����ʧ�ܣ�����-1
}


int main()
{
    int n=10;
    int a[n]={1,3,4,6,7,8,10,11,12,15};
    printf("%d %d\n",binarySearch(a,0,n-1,6),binarySearch(a,0,n-1,9));
    return 0;
}