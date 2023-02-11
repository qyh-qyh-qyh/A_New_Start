typedef struct {
    int count[10000];
    int front;
    int rear;
} RecentCounter;//问题一，提示了t是递增的，可以用队列来实现，这里采取的是数组的方式，一般都用数组


RecentCounter* recentCounterCreate() {//只是用来初始化内存空间，没有输入数据
    RecentCounter*input=NULL;
    input=(RecentCounter*)malloc(sizeof(RecentCounter));
    input->front=0;
    input->rear=0;
    return input;
}//初始化掌握的不错，先申请内存，然后给结构体内有的有用的赋值，问题二，初始化没有输入数据进结构体队列

int recentCounterPing(RecentCounter* obj, int t) {//问题三，这里才是一个个数据慢慢输入并且按照队列出队
    obj->count[obj->rear++]=t;
    //printf("%d",obj->rear);
    while(obj->front!=obj->rear){//问题四，意识很好这次，考虑到了空内存的问题
        if((obj->count[obj->rear-1])-(obj->count[obj->front])>3000){//问题五，注意rear下标，有++时要小心
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
