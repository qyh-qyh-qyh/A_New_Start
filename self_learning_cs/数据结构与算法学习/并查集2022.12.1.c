#include<stdio.h>
#include<stdlib.h>

int find(int s[100],int num){
    if(s[num]<0){
        return num;
    }
    else{
        return s[num]=find(s,s[num]);
    }
}

void bing(int s[100],int num1,int num2){
    int root1=find(s,num1-1);
    int root2=find(s,num2-1);
    if(root1<root2){
        s[root1]+=s[root2];
        s[root2]=root1;
    }
    else{
        s[root2]+=s[root1];
        s[root1]=root2;
    }
}

int calculate(int s[100],int num3){
    int root3=find(s,num3-1);
    int res=-s[root3];
    return res;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int picture[500];
    for(i=0;i<n;i++){
        picture[i]=-1;
    }
    char ch[3];
    
    int a,b;
    int roota,rootb;
    int count;
    for(i=0;i<m;i++){
        scanf("%s",ch);
        if(ch[0]=='C'){
            scanf("%d%d",&a,&b);
            bing(picture,a-1,b-1);
        }
        else if(ch[0]=='Q'&&ch[1]=='1'){
            scanf("%d%d",&a,&b);
            roota=find(picture,a-1);
            rootb=find(picture,b-1);
            if(roota==rootb){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            scanf("%d",&a);
            count=calculate(picture,a-1);
            printf("%d\n",count);
        }
    }
    return 0;
}
//晚些来修改并标注这段代码，报错原因是因为ch这个字符串被反复读取
//问题一。这个不同字符串的比较可以从前面一个两个看
//问题二。return后要加分号 
