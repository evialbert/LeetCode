class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        int k = n % 14 == 0 ? 14 : n % 14;
        while(k > 0) {
            int[] local = cells.clone();
            cells[0] = 0;
            for(int i = 1; i < 7; i++) {
                cells[i] = (local[i-1] == local[i+1] ? 1 : 0);
            }
            cells[7] = 0;
            k--;
        }
        return cells;
    }
}