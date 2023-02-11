int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    //贪心策略：
    //第一步：确定最优解成立条件，看是否只有一个因素，如果多于一个则用dynamic programming
    //第二步：循环：还有可行解
    //第三步：执行并取出最优解
    //第四步：缩小问题规模：用双指针或者for循环减小问题规模

    //本题其实是找出一个绕圈的最优解，然后判断是否可行

    //问题一，本题贪心关键是若一个点能到达一个最远点，则这个点之间所有点的最远点都不会超过之前那个点
    int res=0;
    int i,j;
    int n=gasSize;
    for(i=0;i<n;){//注意细节，贪心不用i++
        for(j=0;j<n;j++){
            int k=(i+j)%n;//问题二，这步很关键，这样可以确定这种跑圈问题使得大索引能按顺序到小索引
            res+=(gas[k]-cost[k]);
            if(res<0){
                break;
            }
        }
        if(j==n){
            return i;//表示成功
        }
        i=i+j+1;//问题三，贪心的思想关键步骤
        res=0;
    }
    return -1;//表示找完了都没找到 
}
