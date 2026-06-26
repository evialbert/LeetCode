class Solution {
    public boolean checkGoodInteger(int n) {
        int digitSum = 0;
        int sqSum = 0;

        while(n> 0){
            int ld = n%10;
            n /= 10;
            digitSum += ld;
            sqSum += ld*ld;
        }

        if((sqSum - digitSum) >= 50){
            return true;
        }
        return false;
    }
}