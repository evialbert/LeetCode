class Solution {
    public int sumCounts(List<Integer> nums) {
        int len = nums.size();
        int sum = 0;
        
        for(int i = 0; i < len; i++) {
            Set<Integer> set = new HashSet<>();
            
            for(int j = i; j < len; j++) {
                set.add(nums.get(j));
                sum += set.size()*set.size();
            }
        }

        // sum += len;
        return sum;
    }
}