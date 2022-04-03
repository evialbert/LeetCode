class Solution {
    public int maxProfit(int[] inventory, int orders) {
        int lo = 1, hi = (int)1e9, m = hi + 7;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            long need = 0;
            for (int n : inventory){
                need += Math.max(0, n - mid);
            }
            if (need < orders){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }

        long ans = 0;
        for (int n : inventory){
            ans = (ans + Math.max(0L, 1L*(lo + 1 + n)*(n - lo)/2)) % m;
            orders -= Math.max(0, n - lo);
        }

        return (int)((ans + 1L*orders * lo) % m);
    }
}