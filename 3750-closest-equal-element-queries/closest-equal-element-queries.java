
class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        HashMap<Integer, TreeSet<Integer>> h = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        // Store indices of each number in a TreeSet
        for (int i = 0; i < nums.length; i++) {
            h.computeIfAbsent(nums[i], k -> new TreeSet<>()).add(i);
        }

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int queryIndex = queries[i];
            int val = nums[queryIndex];
            TreeSet<Integer> indexSet = h.get(val);

            if (indexSet.size() == 1) {
                ans.add(-1);
                continue;
            }

            int minAns = nums.length;

            // Get next occurrence (higher)
            Integer next = indexSet.higher(queryIndex);
            if (next != null) {
                int diff = next - queryIndex;
                minAns = Math.min(minAns, Math.min(diff, nums.length - diff));
            }

            // Get previous occurrence (lower)
            Integer prev = indexSet.lower(queryIndex);
            if (prev != null) {
                int diff = queryIndex - prev;
                minAns = Math.min(minAns, Math.min(diff, nums.length - diff));
            }

            // Handle circular case
            Integer first = indexSet.first();
            Integer last = indexSet.last();
            if (queryIndex == first) {
                int diff = last - first;
                minAns = Math.min(minAns, Math.min(diff, nums.length - diff));
            }
            if (queryIndex == last) {
                int diff = last - first;
                minAns = Math.min(minAns, Math.min(diff, nums.length - diff));
            }

            ans.add(minAns);
        }

        return ans;
    }
}