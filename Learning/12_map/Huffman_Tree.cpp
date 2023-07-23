#include <cstdio>
#include <queue>
using namespace std;

//哈夫曼编码，每个字符的出现次数为权重建立哈夫曼树，然后最后总的01字符串长度就是该树的带权路径长度
//代表小顶堆的优先级队列
priority_queue<long long,vector<long long>,greater<long long> > q;

int main(){
    int n;
    long long tmp,x,y,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&tmp);
        q.push(tmp);
    }

    while(q.size()>1){ //边界为优先级队列中至少有两个元素
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        q.push(x+y);
        ans+=(x+y);
    }
    printf("%lld\n",ans);
    return 0;
}