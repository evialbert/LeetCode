class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int sum = 0;
        Set<Integer> set = new HashSet<>();
        int count = 0;
        set.add(0);
        for(int i : nums) {
            sum += i;
            if(set.contains(sum - target)) {
                count++;
                sum = 0;
                set = new HashSet<>();
                set.add(0);
            }else {
                set.add(sum);
            }
        }
        return count;
    }
}