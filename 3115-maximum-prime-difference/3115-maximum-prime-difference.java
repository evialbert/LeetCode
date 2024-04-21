class Solution {

    static boolean isPrime(int n){
        if(n==1) return false;
        if(n==2) return true;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    public int maximumPrimeDifference(int[] arr) {

        int a = -1;
        int b = -1;
        int n = arr.length;
        for(int i=0; i<n; i++){
            if(isPrime(arr[i])){
                a = i;
                break;
            }
        }

        for(int i=n-1; i>=0; i--){
            if(isPrime(arr[i])){
                b = i;
                break;
            }
        }
        return b-a;
    }
}