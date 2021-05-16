class Solution {
    public int minSteps(int n) {
        int[] arr=new int[n];
        arr[0]=0;
        for(int i=2;i<=n;i++){
            int ld=leastDivisor(i);
            
            arr[i-1]= i==ld ? i : arr[i/ld-1]+ld;
            
        }
        return arr[n-1];
    }
    public int leastDivisor(int n){
        for(int i=2;i*i<=n;i++)
            if(n%i==0) return i;
        return n;
    }
}