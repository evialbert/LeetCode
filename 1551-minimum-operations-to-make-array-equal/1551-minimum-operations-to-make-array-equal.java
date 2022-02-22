class Solution {
    public int minOperations(int n) {
        int lastEle = (2*(n-1))+1;
        int val = (lastEle - n);
        int sum = 0;
        while(val > 0){
            sum+=val;
            val-=2;
        }
        return sum;
    }
}