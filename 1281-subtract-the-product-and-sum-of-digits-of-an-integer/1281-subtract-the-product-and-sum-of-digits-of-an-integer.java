class Solution {
    public int subtractProductAndSum(int n) {
        
        int sum = 0;
        int prod = 1;
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            sum += temp;
            prod *= temp;
        }
        return prod - sum;
    }
}