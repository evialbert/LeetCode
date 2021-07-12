class Solution {
    public int consecutiveNumbersSum(int N) {
        int count=0;
        for(int i=1;N-(i*(i-1)/2)>0;i++){
            int val = N-(i*(i-1)/2);
            if(val%i==0)count++;
        }
        return count;
    }
}