#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=11;
int n,p[maxn];  //pΪ��ǰ�����е�����nΪȫ���е�λ��
bool hashTable[maxn]={false};  //����һ��hash���æ�ж�x�Ƿ��Ѿ�������


//����ǰ���ֵĵ�indxλ
void generateP(int index){
    if(index == n+1){  //�ݹ�߽磬���1~n+1λ������
        for(int i=1;i<=n;i++){
            printf("%d",p[i]);  //�����ǰ���� 
        }
        printf("\n");
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

int main()
{
    scanf("%d",&n);
    generateP(1);
    return 0;
}