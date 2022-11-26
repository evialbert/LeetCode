class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        if(cost1 < cost2)   swap(cost1,cost2);
        
        int totalPossibleBuys = (total/cost1);
        for(int i=0;i<=totalPossibleBuys;i++){
            int newCost = total - (cost1 * i);
            if(newCost >= 0){
                ans += (newCost/cost2) + 1;                
            }
        }
        
        if(ans == 0)    return 1;
        
        return ans;
    }
};