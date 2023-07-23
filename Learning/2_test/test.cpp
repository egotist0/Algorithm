#include <cstdio>
#include <cstring>

// const int num=1000;
// int total[num]={0};

int main(){
    int n,id,score,tmp=1;
    scanf("%d",&n);
    int total[n+1]={0};
    for(int i=1;i<=n;i++){
        scanf("%d%d",&id,&score);
        total[id]+=score;
    }

    for(int i =1;i<=n;i++){
        if(total[i]>total[tmp]){
            tmp=i;
        }
    }
    printf("%d %d\n",tmp,total[tmp]);
    return 0;
}