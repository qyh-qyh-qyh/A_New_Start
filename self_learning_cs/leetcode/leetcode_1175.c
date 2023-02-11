bool isPrime(int n){//问题三，别忘了1的情况，这样才算完整
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

long permutation(int n){//问题一，定义长整型
     int i;
     long res=1;
     for(i=1;i<=n;i++){
        res*=i; 
        res%=1000000007;//问题二，为什么是每次循环都要取余一次
     }
     return res;
}

int numPrimeArrangements(int n){
    int num;//计算质数的数目
    int i;
    for(i=1;i<=n;i++){
        if(isPrime(i)){
            num++;
        }
    }
    int res=permutation(num)*permutation(n-num)%1000000007;//问题四，为什么这个还要取余
    return res;
}
