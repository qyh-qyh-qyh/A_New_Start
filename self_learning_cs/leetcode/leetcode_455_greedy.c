#include<stdio.h>
#include<stdlib.h> 

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int res=0;
    int i,j=sSize-1;
    if(sSize==0){//�ǵñ����������
        return 0;
    }

    for(i=gSize-1;i>=0;i--){
        if(g[i]<=s[j]){//�ǵ�Ҫ������
            if(j<0){
                break;
            }
            j--;
            res++;
        }
        
    }
    return res;
}

int main(){
	int len1,len2;
	scanf("%d%d",&len1,&len2);
	int i;
	int g[len1],s[len2];
	for(i=0;i<len1;i++){
		scanf("%d",&g[i]);
	}
	for(i=0;i<len2;i++){
		scanf("%d",&s[i]);
	}
	int res=findContentChildren(g,len1,s,len2);
	printf("%d",res);
	return 0;
}
