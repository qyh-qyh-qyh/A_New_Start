int dist(int i,int j,int rCenter,int cCenter){
    return fabs(i-rCenter)+fabs(j-cCenter);
}


int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes){//其实就是广度优先搜索的实现，还可以用桶排序
     //方法一，使用桶排序，函数很多都是传入输入数据，然后再函数体内采用数据结构解决（数据结构在函数内初始化），最后在函数内放回一个目标返回值
     int maxdist=fmax(rCenter,rows-1-rCenter)+fmax(cCenter,cols-1-cCenter);//问题一，距离最大点在四个角取到,很好的表示法
     int bucket[maxdist+1][2*(rows+cols)];//问题二，确定桶的最大容量，这个列容量是由几何关系确定的
     int bucketSize[maxdist+1];
     memset(bucketSize,0,sizeof(bucketSize));//问题三，每一列都要记录的话要设置这样一个数组
     int i,j;
     for(i=0;i<rows;i++){
         for(j=0;j<cols;j++){
             int distance=dist(i,j,rCenter,cCenter);
             int*temp=malloc(sizeof(int)*2);
             temp[0]=i;
             temp[1]=j;
             bucket[distance][bucketSize[distance]++]=temp;//问题四，上述储存过程切记，并且二维数组里面可以储存一个数组（点的坐标是一个数组）
         }
     }
     

     int**res=malloc(sizeof(int*)*rows*cols);//问题五，结果数组出现了，这个是要返回的，数组的数组的初始化方式
     for(i=0;i<rows*cols;i++){
         res[i]=malloc(sizeof(int)*2);
     }
     *returnSize=0;
     for(i=0;i<maxdist+1;i++){
         for(j=0;j<bucketSize[i];j++){
             res[(*returnSize)++]=bucket[i][j];
         }
     }
     return res;
}
