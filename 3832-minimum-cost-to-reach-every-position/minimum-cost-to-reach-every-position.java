class Solution {
    public int[] minCosts(int[] cost) {
        int curr = Integer.MAX_VALUE;
        int n = cost.length;
        for(int i=0;i<n;i++)
        {
            if(curr<cost[i])
            {
                
                cost[i] = curr;
            }
            else
            {
                curr = cost[i];
            }
        }
        return cost;
    }
}