#include"uthash.h"
//δ��ɣ�����2544�� 
typedef struct hashtable{
    int color;
    int count;//����һ�������color��ʾ����ʵ��key������ʾindex�±꣬��count��ʾ����attribute�����������ʣ������ã�
    UT_hash_handle hh;//�������hash�����Ҫ�еģ�ֻ��ǰ���д
}hash;




int minimumSwitchingTimes(int** source, int sourceSize, int* sourceColSize, int** target, int targetSize, int* targetColSize){
    struct hashtable*ht=NULL;//���������������Ҫ�еģ���һ���յ�
    struct hashtable*delete;//����ɾ����
    struct hashtable*temp;//��ʱ�ģ�����������
    int row=sourceSize;
    int column=sourceColSize[0];//�����ģ���סÿ����������
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            HASH_FIND_INT(ht,&source[i][j],temp);//�����壬ע�⴫��Ĳ���������������ֵ
            if(temp==NULL){
                temp=malloc(sizeof(hash));
                temp->color=source[i][j];
                temp->count=1;
                HASH_ADD_INT(ht,temp->color,temp);//��������ע������������������Ĳ���    
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
            if(temp==NULL||!temp->count){//�����ߣ���̾�ŵĺ��岢�����countֻ�Ǳ�ʾ��������ֵһֱ������hash������
               res++;
            }
            else{
                temp->count--;
            }
        }
    }
    HASH_ITER(hh,ht,delete,temp){//����ˣ���ʾѭ����ע�����
         HASH_DEL(ht,delete);
         free(delete);
    }
    return res;
}
