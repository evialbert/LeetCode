class Solution {
     public int twoCitySchedCost(int[][] costs) {
        int k = costs.length/2 - 1;
        quickSelect(costs, k, 0, costs.length - 1);
        
        int totalCost = 0;
        
        for(int i = 0; i < costs.length/2; i++) {
            totalCost += costs[i][0];
            totalCost += costs[costs.length - 1 - i][1];
        }
        
        return totalCost;
    }
    
    private void quickSelect(int[][] costs, int k, int i, int j) {
        int low = i;
        
        for(int m = i; m < j; m++) {
            if(diff(costs, m) < diff(costs, j)){
                swap(costs, m, low);
                low++;
            }
        }
        
        swap(costs, low, j);
        
        if(low == k) return;
        
        if(low < k) {
            quickSelect(costs, k, low + 1, j);
        } else {
            quickSelect(costs, k, i, low - 1);
        }
    }
    
    private int diff(int[][] costs, int index) {
        return costs[index][0] - costs[index][1];
    }
    
    private void swap(int[][] costs, int i, int j) {
        int[] tmp = costs[i];
        costs[i] = costs[j];
        costs[j] = tmp;
    }
}