class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> temp = new ArrayList<>();
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                temp.add(grid[i][j]);
            }
        }
        
        Collections.sort(temp);
        int result = 0, left = 0, right = temp.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if((temp.get(mid) - temp.get(left)) % x != 0 
               || (temp.get(right) - temp.get(mid)) % x != 0) {
                return -1;
            }
            result += (temp.get(right--) - temp.get(left++)) / x;
        }
        return result;
    }
}