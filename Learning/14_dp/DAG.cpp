//动态规划可用于直接求最长路径

//求整个DAG中的最长路径（不固定起点和终点）

//dp[i]表示i号顶点出发能达到的最长路径（逆拓扑序）
//初始化dp[i]为0
int dp(int i){
    id(dp[i]>0) return dp[i]; //dp[i]已计算得到，初始都初始化为0，没有得到就会调用递归求解，形成类似于逆拓扑的顺序

    for(int j=0;j<n;lj++){ //遍历i的所有后继结点
        if(g[i][j]!=inf){ //存在边
            int tmp=dp[j]+g[i][k]; //！！！！单独计算，防止if中调用dp两次
            if(tmp>dp[i]){ //可以获得更长路径
                dp[i]=tmp;
                choice[i]=j; //i后顶点的后继为j（如果有多条，可以类似dij换成vector来存储）
            }
        }
    }

    return dp[i]; //返回计算完毕的dp[i]
}

//调用输出路径函数前必须要先得到最大的dp[i]，然后从i开始调用
void printPath(int i){
    printf("%d",i);
    while(choice[i]!=-1){ //choice数组都先初始化为-1，递归边界就是出度为0的节点
        i=choice[i];
        printf("->%d",i);
    }
}

//dp[i]也可以表示为i号顶点结尾获得的最长路径长度（拓扑序列）
//但这种情况下不方便于得到字典序最小的方案


//固定终点求DAG的最长路径
//初始化dp数组为-inf（一个负的大数）,然后设置一个vis数组表示顶点是否已被计算
int dp(int i){
    if(vis[i]) return dp[i]; //dp[i]已计算得到
    vis[i]=true;
    for(int j=0;j<n;j++){
        if(g[i][j]!=inf){ //存在边
            dp[i]=max(dp[i],dp[j]+g[i][j]);
        }
    }
    return dp[i]; //返回计算完毕的dp[i]
}
//记录方案的方式与之前一致
//dp[i]表示i为结尾的最长路径求解更方便，但是也不方便于处理字典序最小的情况


//可用于求解矩形嵌套问题