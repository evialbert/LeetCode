class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        int[] bits = new int[n];
        Arrays.fill(bits, 1);
        return maxScore(nums, bits, 1, new HashMap<Integer, Integer>());
    }
    
    private int maxScore(int[] nums, int[] bits, int index, Map<Integer,Integer> memo) {
        int num = getNum(bits);
        if(num == 0) return 0;
        if(memo.containsKey(num)) return memo.get(num);
        int result = 0;
        for(int i = 0; i < bits.length; i++) {
            for(int j = i + 1; j < bits.length; j++) {
                if(bits[i] == 1 && bits[j] == 1) {
                    bits[i] = 0;
                    bits[j] = 0;
                    result = Math.max(result, index * gcd(nums[i], nums[j]) + maxScore(nums, bits, index + 1, memo));
                    bits[i] = 1;
                    bits[j] = 1;
                }
            }
        }
        
        memo.put(num, result);
        return memo.get(num);
    } 
    
    private int gcd(int a, int b) {
        return a == 0 ? b : gcd(b % a, a);
    }
    
    private int getNum(int[] bits) {
        int result = 0;
        for(int i = 0; i < bits.length; i++)
            result = (result * 2) + bits[i];
        return result;
    }
}