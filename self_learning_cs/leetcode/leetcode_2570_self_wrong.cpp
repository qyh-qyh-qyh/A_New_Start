//�������д����ȥ���뷨����Ϊ�п����еĲ�����֮ǰ���Ѿ��������Σ� 

int dfs_count(struct TreeNode*root,int floor,int ceiling){//����һ�����ݹ龹Ȼ������Ц�� 
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
    int i,j;//����������������С�������⣬��Ҳ����ȥ�����⣬ֻ�ܿ��� 
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
