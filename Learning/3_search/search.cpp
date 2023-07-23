#include <cstdio>
#include <cstring>

int main(){
    int n,x,i=0;
    while (scanf("%d",&n)!= EOF)
    {
        int a[n]={};
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++){
            if (a[i]==x){
                printf("%d",i);
                break;
            }
        }
        if(i==n){
                printf("-1\n");
        }
    }

    return 0;

}