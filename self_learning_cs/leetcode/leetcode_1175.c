bool isPrime(int n){//��������������1�������������������
    if(n==1){
        return false;
    }
    int flag=1;
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            flag=0;
            break;
        }
    }
    return flag==1;
}

long permutation(int n){//����һ�����峤����
     int i;
     long res=1;
     for(i=1;i<=n;i++){
        res*=i; 
        res%=1000000007;//�������Ϊʲô��ÿ��ѭ����Ҫȡ��һ��
     }
     return res;
}

int numPrimeArrangements(int n){
    int num;//������������Ŀ
    int i;
    for(i=1;i<=n;i++){
        if(isPrime(i)){
            num++;
        }
    }
    int res=permutation(num)*permutation(n-num)%1000000007;//�����ģ�Ϊʲô�����Ҫȡ��
    return res;
}
