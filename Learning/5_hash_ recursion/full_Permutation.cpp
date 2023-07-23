#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=11;
int n,p[maxn];  //p为当前所排列的数，n为全排列的位数
bool hashTable[maxn]={false};  //定义一个hash表帮忙判断x是否已经被调用


//处理当前数字的第indx位
void generateP(int index){
    if(index == n+1){  //递归边界，完成1~n+1位的排列
        for(int i=1;i<=n;i++){
            printf("%d",p[i]);  //输出当前数字 
        }
        printf("\n");
        return;
    }

    for(int x=1;x<=n;x++){
        if(hashTable[x]==false){
            p[index]=x;
            hashTable[x]=true;
            generateP(index+1);

            hashTable[x]=false;  //注意还原状态
        }
    }
}

int main()
{
    scanf("%d",&n);
    generateP(1);
    return 0;
}