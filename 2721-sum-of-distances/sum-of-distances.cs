public class Solution {
    public long[] Distance(int[] nums) {
        int n = nums.Length;
        var groups = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            if (!groups.ContainsKey(nums[i])) {
                groups[nums[i]] = new List<int>();
            }
            groups[nums[i]].Add(i);
        }
        long[] res = new long[n];
        foreach (var group in groups.Values) {
            long total = 0;
            foreach (int idx in group) {
                total += idx;
            }
            long prefixTotal = 0;
            int sz = group.Count;
            for (int i = 0; i < sz; i++) {
                int idx = group[i];
                res[idx] = total - prefixTotal * 2 + (long)idx * (2 * i - sz);
                prefixTotal += idx;
            }
        }
        return res;
    }
}