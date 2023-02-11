//主函数中错误的去重想法（因为有可能有的部分在之前就已经算了两次） 

int dfs_count(struct TreeNode*root,int floor,int ceiling){//问题一·树递归竟然做对了笑了 
    int count;
    if(!root){
        return 0;
    }
    if(root->val>=floor&&root->val<=ceiling){
        return dfs_count(root->left,floor,ceiling)+dfs_count(root->right,floor,ceiling)+1;
    }
    else{
        return dfs_count(root->left,floor,ceiling)+dfs_count(root->right,floor,ceiling);
    }
}

int getNumber(struct TreeNode* root, int** ops, int opsSize, int* opsColSize){
    int i,j;//问题二，不是最大最小区间问题，但也不是去重问题，只能看答案 
    int count=0;
    for(i=0;i<opsSize;i++){
        if(ops[i][0]==1){
           count+=dfs_count(root,ops[i][1],ops[i][2]);
           printf("%d\n",count);
           for(j=0;j<i;j++){
              if(ops[j][0]==1){
                  if(ops[i][1]<ops[j][2]&&ops[i][1]>ops[j][1]){
                      count-=dfs_count(root,ops[i][1],ops[j][2]);
                      printf("%d\n",count);
                  }
                  else if(ops[i][2]>ops[j][1]&&ops[i][2]<ops[j][2]){
                      count-=dfs_count(root,ops[j][1],ops[i][2]);
                      printf("%d",count);
                  }              
                }
           }
        }
    }
    return count;
}
