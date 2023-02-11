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
//问题一.这题思路很巧妙，从结果出发，发现对于固定长度只有两种可能的结果，然后再观察，发现这两种
//结果相互对称，操作数相加正好是字符串长度，所以采用直接求解一种的办法（宏观解法）
