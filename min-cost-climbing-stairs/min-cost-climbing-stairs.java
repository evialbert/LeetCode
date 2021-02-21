class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int l2 = 0;
        int l1 = 0;
        for(int c : cost){
            int d = (l1 < l2 ? l1 : l2) + c;
            l2 = l1;
            l1 = d;
        }
        return l1 < l2 ? l1 : l2;
    }
}