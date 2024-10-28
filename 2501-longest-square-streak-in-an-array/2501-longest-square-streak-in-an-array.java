class Solution {
    public int longestSquareStreak(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int longestStreak = 1;
        for(int num : nums){
            set.add(num);
        }
        for(int num : nums){
            int current = 1;
            boolean flag = true;
            while(num<1000){
                if(set.contains(num*num)){
                    current++;
                    num = num*num;
                } else {
                    break;
                }
            }
         longestStreak = Math.max(longestStreak, current);
        }
        return longestStreak < 2 ? -1 : longestStreak;
    }
}