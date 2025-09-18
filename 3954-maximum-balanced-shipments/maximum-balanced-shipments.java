class Solution {
    public int maxBalancedShipments(int[] weight) {
        int n = weight.length,maxWt = Integer.MIN_VALUE,cnt = 0;

        for(int i=0;i<n;i++) {
            maxWt = Math.max(maxWt,weight[i]);

            if(weight[i] < maxWt) {
                cnt++;
                maxWt = Integer.MIN_VALUE;
            }
        }

        return cnt;
    }
}