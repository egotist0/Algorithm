#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int hashFunc(char s[],int len){  //hash函数，将字符串s转化为整数(全为大写字母的情况)
    int id = 0;
    for (int i = 0;i<len;i++){
        id=id*26+(s[i]-'A');
    }
    return id;
}


int hashFunc(char s[],int len){  //hash函数，将字符串s转化为整数(存在小写字母的情况)，大写0~25，小写26~51
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


//数字处理办法

/*
1. 按照小写字母的处理办法，增大进制到62
2. 确定位置的可以直接加
*/