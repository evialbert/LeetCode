class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total = n*n;
        int total_wt_possible = total*w;

        if(total_wt_possible <= maxWeight)
            return total;
     
        return min((n*n),maxWeight/w);
    }
};