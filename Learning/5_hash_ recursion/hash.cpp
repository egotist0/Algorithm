#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int hashFunc(char s[],int len){  //hash���������ַ���sת��Ϊ����(ȫΪ��д��ĸ�����)
    int id = 0;
    for (int i = 0;i<len;i++){
        id=id*26+(s[i]-'A');
    }
    return id;
}


int hashFunc(char s[],int len){  //hash���������ַ���sת��Ϊ����(����Сд��ĸ�����)����д0~25��Сд26~51
    int id = 0;
    for (int i = 0;i<len;i++){
        if (s[i]>='A' && s[i]<='Z')
        {
            id=id*52+(s[i]-'A');
        }
        else if (s[i]>='a' && s[i]<='z')
        {
            id=id*52+(s[i]-'a')+26;
        }
    }
    return id;
}


//���ִ���취

/*
1. ����Сд��ĸ�Ĵ���취��������Ƶ�62
2. ȷ��λ�õĿ���ֱ�Ӽ�
*/