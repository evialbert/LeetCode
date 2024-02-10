class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        var total = 0;
        var count = new int[101];
        for (var n : nums) {
            count[n]++;
            total += n;
        }
        var result = new ArrayList<Integer>();
        var localSum = 0;
        for (int i = 100; i >= 0; i--) {
            if (count[i] > 0) {
                for (int j = 0; j < count[i]; j++) {
                    result.add(i);
                    total -= i;
                    localSum += i;
                    if (total < localSum) {
                        return result;
                    }
                }                
            }
        }
        return Collections.emptyList();
    }
}