typedef struct {
    int count[10000];
    int front;
    int rear;
} RecentCounter;//����һ����ʾ��t�ǵ����ģ������ö�����ʵ�֣������ȡ��������ķ�ʽ��һ�㶼������


RecentCounter* recentCounterCreate() {//ֻ��������ʼ���ڴ�ռ䣬û����������
    RecentCounter*input=NULL;
    input=(RecentCounter*)malloc(sizeof(RecentCounter));
    input->front=0;
    input->rear=0;
    return input;
}//��ʼ�����յĲ����������ڴ棬Ȼ����ṹ�����е����õĸ�ֵ�����������ʼ��û���������ݽ��ṹ�����

int recentCounterPing(RecentCounter* obj, int t) {//���������������һ���������������벢�Ұ��ն��г���
    obj->count[obj->rear++]=t;
    //printf("%d",obj->rear);
    while(obj->front!=obj->rear){//�����ģ���ʶ�ܺ���Σ����ǵ��˿��ڴ������
        if((obj->count[obj->rear-1])-(obj->count[obj->front])>3000){//�����壬ע��rear�±꣬��++ʱҪС��
            obj->front++;
        }
        else break; 
    }
    return obj->rear-obj->front;
}

void recentCounterFree(RecentCounter* obj) {
     free(obj);
     return 0;
}
