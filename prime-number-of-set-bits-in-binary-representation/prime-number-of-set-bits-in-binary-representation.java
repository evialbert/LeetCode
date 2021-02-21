class Solution {
    public int countPrimeSetBits(int L, int R) {
        int result = 0;
        for(int i=L;i<=R;i++){
            int temp = i;
            int count = 0;
            while(temp>0){
                if(temp%2==1){
                    count++;
                }
                temp >>= 1;
            }
            if(isPrime(count)){
                result++;
            }
        }
        return result;
    }
    
    private boolean isPrime(int a){
        if(a<=1){
            return false;
        }
        for(int i=2;i<=Math.sqrt(a);i++){
            if(a%i==0){
                return false;
            }
        }
        return true;
    }
}