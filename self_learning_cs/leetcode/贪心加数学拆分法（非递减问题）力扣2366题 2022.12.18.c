long long minimumReplacement(int* nums, int numsSize){
      long long procedure_num=0;
      int divisor=nums[numsSize-1];
      //printf("%d\n",divisor);
      int i;
      int times=0;//����
      //int temp;//���ڼ���dividor��
      for(i=numsSize-2;i>=0;i--){//����һ���ǵݼ����У�����Ӧ�ô����һ����ʼ������Ҫ��
          if(nums[i]%divisor==0){//��������ֲ�ֵ����
              times=nums[i]/divisor;
              //printf("%d\n",times);
              procedure_num+=(times-1);
          }
          else if(nums[i]%divisor!=0&&nums[i]/divisor>0){
              times=nums[i]/divisor;
              procedure_num+=times;
             // temp=divisor+(nums[i]%divisor);
              //divisor=temp/2;
              divisor=nums[i]/(times+1);//��������ʹ��ÿ������ֺ����
          }
          else divisor=nums[i];
      }
      return procedure_num;
}
