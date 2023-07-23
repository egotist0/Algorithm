#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=11;
int n,p[maxn],count=0;  //p为当前所排列的数，n为全排列的位数
bool hashTable[maxn]={false};  //定义一个hash表帮忙判断x是否已经被调用


//处理当前数字的第indx位(暴力法)
void generateP(int index){
    bool flag=true;
    if(index == n+1){  //递归边界，完成1~n+1位的排列
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(i-j)==abs(p[i]-p[j])){
                    flag=false;
                    break;
                }
            }
        }

        if(flag==true) count++;
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



//处理当前数字的第indx位(回溯法)
void generateP_(int index){
    if(index == n+1){  //递归边界，完成1~n+1位的排列
        count++;
        return;
    }

    for(int x=1;x<=n;x++){
        if(hashTable[x]==false){
            bool flag=true;
            for(int pre=1;pre<x;pre++){
               if((abs(index-pre)==abs(x-p[pre]))){
                   flag=false;
                   break;
               }
           }


        if(flag){
            p[index]=x;
            hashTable[x]=true;
            generateP_(index+1);
            hashTable[x]=false;  //递归完毕，还原第x行为未占用
        }
        }
    }
}



int main()
{
    scanf("%d",&n);
    generateP(1);
    return 0;
}