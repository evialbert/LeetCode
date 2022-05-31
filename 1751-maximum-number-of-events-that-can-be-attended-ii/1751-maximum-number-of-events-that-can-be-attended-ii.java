class Solution {
    public int maxValue(int[][] events, int k) {
        if (k == 1) {
            return Arrays.stream(events).max(Comparator.comparingInt(e -> e[2])).get()[2];
        }
        
		int n = events.length;
        Arrays.sort(events, (a, b) -> (a[0] - b[0]));
		
        int[][] memo = new int[n][k + 1];
        int res = dfs(events, 0, k, memo);
        
        return res;
    }
    
    private int dfs(int[][] events, int i, int k, int[][] memo) {
        if (k == 0 || i >= events.length) {
            return 0;
        }
        if (memo[i][k] > 0) {
            return memo[i][k];
        }
        
        int idx = binarySearch(events, events[i][1] + 1, i + 1);
        int use = events[i][2] + dfs(events, idx, k - 1, memo);
        
        int notUse = dfs(events, i + 1, k, memo);
        
        int res = Math.max(use, notUse);
        memo[i][k] = res;
        
        return res;
    }
    
    private int binarySearch(int[][] events, int i, int st) {
        
        if (st >= events.length) {
            return st;
        }
        
        int end = events.length - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (events[mid][0] < i) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return events[st][0] >= i ? st : st + 1;
    }
}