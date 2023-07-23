#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=11;
int n,p[maxn],count=0;  //pΪ��ǰ�����е�����nΪȫ���е�λ��
bool hashTable[maxn]={false};  //����һ��hash���æ�ж�x�Ƿ��Ѿ�������


//����ǰ���ֵĵ�indxλ(������)
void generateP(int index){
    bool flag=true;
    if(index == n+1){  //�ݹ�߽磬���1~n+1λ������
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

            hashTable[x]=false;  //ע�⻹ԭ״̬
        }
    }
}



//����ǰ���ֵĵ�indxλ(���ݷ�)
void generateP_(int index){
    if(index == n+1){  //�ݹ�߽磬���1~n+1λ������
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
            hashTable[x]=false;  //�ݹ���ϣ���ԭ��x��Ϊδռ��
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