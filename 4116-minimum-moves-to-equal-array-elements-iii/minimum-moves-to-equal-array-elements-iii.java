class Solution {
    public int minMoves(int[] nums) {
        int sum = 0, msf = 0, msfCount = 0;
        for(int num : nums){
            if(msf == num)msfCount++;
            else {
                msf = Math.max(msf, num);
                msfCount = 1;
            }

            sum+=num;
        }
        sum -= msfCount*msf;
        return (nums.length-msfCount)*msf - sum;
    }
}