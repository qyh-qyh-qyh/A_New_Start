int minOperations(char * s){
    int procedure_num=0;
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++){
        if((i%2==0&&s[i]=='1')||(i%2==1&&s[i]=='0')){
            procedure_num++;
        }
    }
    int symmetric=len-procedure_num;
    if(symmetric<procedure_num){
        return symmetric;
    }
    else return procedure_num;
}
//����һ.����˼·������ӽ�����������ֶ��ڹ̶�����ֻ�����ֿ��ܵĽ����Ȼ���ٹ۲죬����������
//����໥�Գƣ�����������������ַ������ȣ����Բ���ֱ�����һ�ֵİ취����۽ⷨ��
