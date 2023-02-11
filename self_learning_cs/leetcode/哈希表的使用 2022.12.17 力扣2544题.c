#include"uthash.h"
//未完成，力扣2544题 
typedef struct hashtable{
    int color;
    int count;//问题一。这里的color表示的其实是key，不表示index下标，而count表示的是attribute，附属的性质（很有用）
    UT_hash_handle hh;//问题二。hash表必须要有的，只有前面大写
}hash;




int minimumSwitchingTimes(int** source, int sourceSize, int* sourceColSize, int** target, int targetSize, int* targetColSize){
    struct hashtable*ht=NULL;//问题三，这个必须要有的，建一个空的
    struct hashtable*delete;//用来删除的
    struct hashtable*temp;//临时的，用来做计算
    int row=sourceSize;
    int column=sourceColSize[0];//问题四，记住每个参数含义
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            HASH_FIND_INT(ht,&source[i][j],temp);//问题五，注意传入的参数并理解这个返回值
            if(temp==NULL){
                temp=malloc(sizeof(hash));
                temp->color=source[i][j];
                temp->count=1;
                HASH_ADD_INT(ht,temp->color,temp);//问题六，注意参数并理解这个操作的步骤    
            }
            else{
                temp->count++;
            } 
        }
    }

    int res=0;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            HASH_FIND_INT(ht,&target[i][j],temp);
            if(temp==NULL||!temp->count){//问题七，感叹号的含义并且理解count只是表示数量，但值一直都还在hash表里面
               res++;
            }
            else{
                temp->count--;
            }
        }
    }
    HASH_ITER(hh,ht,delete,temp){//问题八，表示循环，注意参数
         HASH_DEL(ht,delete);
         free(delete);
    }
    return res;
}
