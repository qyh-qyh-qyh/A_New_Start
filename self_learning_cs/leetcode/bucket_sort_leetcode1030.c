int dist(int i,int j,int rCenter,int cCenter){
    return fabs(i-rCenter)+fabs(j-cCenter);
}


int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes){//��ʵ���ǹ������������ʵ�֣���������Ͱ����
     //����һ��ʹ��Ͱ���򣬺����ܶ඼�Ǵ����������ݣ�Ȼ���ٺ������ڲ������ݽṹ��������ݽṹ�ں����ڳ�ʼ����������ں����ڷŻ�һ��Ŀ�귵��ֵ
     int maxdist=fmax(rCenter,rows-1-rCenter)+fmax(cCenter,cols-1-cCenter);//����һ�������������ĸ���ȡ��,�ܺõı�ʾ��
     int bucket[maxdist+1][2*(rows+cols)];//�������ȷ��Ͱ�����������������������ɼ��ι�ϵȷ����
     int bucketSize[maxdist+1];
     memset(bucketSize,0,sizeof(bucketSize));//��������ÿһ�ж�Ҫ��¼�Ļ�Ҫ��������һ������
     int i,j;
     for(i=0;i<rows;i++){
         for(j=0;j<cols;j++){
             int distance=dist(i,j,rCenter,cCenter);
             int*temp=malloc(sizeof(int)*2);
             temp[0]=i;
             temp[1]=j;
             bucket[distance][bucketSize[distance]++]=temp;//�����ģ�������������мǣ����Ҷ�ά����������Դ���һ�����飨���������һ�����飩
         }
     }
     

     int**res=malloc(sizeof(int*)*rows*cols);//�����壬�����������ˣ������Ҫ���صģ����������ĳ�ʼ����ʽ
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
