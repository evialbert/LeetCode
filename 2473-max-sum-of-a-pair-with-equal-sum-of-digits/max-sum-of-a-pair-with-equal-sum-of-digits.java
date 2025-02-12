class Solution {
    public int maximumSum(int[] nums) {
        //so you need to get sum of digits of each number at each index
        //then pick the pair of the largest two
        //only caveat is that we need to ensure their digit sum is the same.
        //solution is to group by digit sums, and find max pair of numbers for each group that has at least 2 numbers
        List<Integer>[] groupByDigits = new ArrayList[83]; // 1999999999
        for(int i = 0; i < nums.length; i++){
            int digitSum = getDigitSum(nums[i]);
            if(groupByDigits[digitSum] == null) groupByDigits[digitSum] = new ArrayList<Integer>();
            groupByDigits[digitSum].add(nums[i]);
        }

        int maxSum = -1;
        for(int i = 0; i < 83; i++){
            if(groupByDigits[i] == null || groupByDigits[i].size() < 2)
                continue;
            int x1 = Math.max(groupByDigits[i].get(0),groupByDigits[i].get(1));
            int x2 = Math.min(groupByDigits[i].get(0),groupByDigits[i].get(1));
            for(int j = 2; j < groupByDigits[i].size(); j++){
                int curr = groupByDigits[i].get(j);
                if(curr >= x1){
                    x2 = x1;
                    x1 = curr;
                }
                else if(curr > x2)
                    x2 = curr;
            }
            maxSum = Math.max(x1+x2, maxSum);
        }
        return maxSum;               
    }
    
    public int getDigitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
}