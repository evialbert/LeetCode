class Solution {
    public int[] minDifference(int[] nums, int[][] queries) {
        List<Integer>[] listArray = new ArrayList[101];
        
        for (int i = 0; i < nums.length; i++) {
            if (listArray[nums[i]] == null) {
                listArray[nums[i]] = new ArrayList<>();
            }
            listArray[nums[i]].add(i);
        }
        
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = query(listArray, queries[i][0], queries[i][1]);
        }
        
        return result;
    }
    
    int query(List<Integer>[] listArray, int start, int end) {
        int prev = -1;
        int diff = Integer.MAX_VALUE;
        
        for (int i = 1; i <= 100; i++) {
            if (listArray[i] == null) { continue; }

            int index = search(listArray[i], start);
            if (index < start || index > end) { continue; }
            
            if (prev == -1) {
                prev = i;
            } else {
                diff = Math.min(diff, i - prev);
                prev = i;
            }
            
            if (diff == 1) { return 1; }
        }
        
        return diff == Integer.MAX_VALUE ? -1 : diff;
    }
    
    private int search(List<Integer> list, int target) {
        int start = 0;
        int end = list.size() - 1;
        
        while (start <= end) {
            int middle = (start + end) / 2;
            int num = list.get(middle);
            if (target < num) {
                end = middle - 1;
            } else if (target > num) {
                start = middle + 1;
            } else {
                return list.get(middle);
            }
        }
        
        return start < list.size() ? list.get(start) : Integer.MAX_VALUE;
    }
}