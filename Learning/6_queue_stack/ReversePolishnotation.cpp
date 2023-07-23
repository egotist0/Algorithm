#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;

//不好对数值和操作符进行判断就设置一个结构体进行存储
struct node
{
    double num; //数值
    char op; //操作符
    bool flag; //true表示数值，false表示操作符
};

string str; //临时存储中缀表达式
stack<node> s; //栈进行操作符存储
queue<node> q; //队列进行后缀表达式存储（也可以用数组）
map<char,int> op; //存储键值对表示操作符的优先级次序


//将中缀表达式转化为后缀表达式
void change(){
    double num;
    node tmp;

    for (int i = 0; i < str.length();)
    {
        if(str[i]>='0' && str[i]<= '9'){ //数值
            tmp.flag=true;
            tmp.num=(str[i++]-'0');
            while (i<str.length() && str[i]>='0' && str[i]<= '9')
            {
                tmp.num=tmp.num*10+(str[i]-'0');
                i++;
            }
            q.push(tmp); //将数值压入后缀表达式中
        }  else{
            tmp.flag=false;
            //此时为操作符
            //当该操作符大于栈顶操作符时，直接压入
            //否则弹出栈中元素直至小于该操作符，入队列
            while (!s.empty() && op[str[i]] <= op[s.top().op]) //出栈压入队列直到小于操作符
            {
                q.push(s.top());
                s.pop();
            }
            tmp.op=str[i];
            s.push(tmp); //压入操作符栈
            i++;
        }
    }

    //如果扫描结束后操作符栈中还有符号，弹出后压入队列中
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}


//计算后缀表达式
double cal(){
    double tmp1,tmp2;
    node cur,tmp; //cur存储当前出队的节点，tmp存储当前要入计算栈的节点
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.flag==true){ //操作数直接入栈
            s.push(cur);
        }else{ //操作符弹出两个数，计算后重新入栈
            tmp2=s.top().num;
            s.pop();
            tmp1=s.top().num;
            s.pop();
            tmp.flag=true;
            //计算操作数
            if(cur.op=='+') tmp.num=tmp1+tmp2;
            if(cur.op=='-') tmp.num=tmp1-tmp2;
            if(cur.op=='*') tmp.num=tmp1*tmp2;
            if(cur.op=='/') tmp.num=tmp1/tmp2;

            s.push(tmp);
        }
    }
    return s.top().num; //最后操作栈顶的元素就是后缀表达式的结果
}

int main(){
    //使用map定义运算符优先级
    op['+']=op['-']=1;
    op['*']=op['/']=2;

    while (getline(cin,str),str!="0")
    {
        //去掉表达式中的所有空格
        for(string::iterator it=str.end();it!=str.begin();it--){
            if(*it==' ') str.erase(it);
        }

        //初始化栈
        while (!s.empty())
        {
            s.pop();
        }
        change();
        printf("%.2f\n",cal());
    }

    return 0;
}