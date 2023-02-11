long long minimumReplacement(int* nums, int numsSize){
      long long procedure_num=0;
      int divisor=nums[numsSize-1];
      //printf("%d\n",divisor);
      int i;
      int times=0;//次数
      //int temp;//用于计算dividor的
      for(i=numsSize-2;i>=0;i--){//问题一，非递减数列，所以应该从最后一个开始（很重要）
          if(nums[i]%divisor==0){//问题二，分拆分的情况
              times=nums[i]/divisor;
              //printf("%d\n",times);
              procedure_num+=(times-1);
          }
          else if(nums[i]%divisor!=0&&nums[i]/divisor>0){
              times=nums[i]/divisor;
              procedure_num+=times;
             // temp=divisor+(nums[i]%divisor);
              //divisor=temp/2;
              divisor=nums[i]/(times+1);//问题三，使得每个数拆分后最大
          }
          else divisor=nums[i];
      }
      return procedure_num;
}
