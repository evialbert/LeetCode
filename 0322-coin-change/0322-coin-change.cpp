class Solution {
    bool check(vector<int>& coins, short index, int cnt, int target){
        long sum = (long) coins[index]*cnt;
        if (sum==target) return true;
        else if (sum > target) {
            if (index == 0) return false;
            
            for (short i = cnt; i>0; i--){
                long take = target - (long)coins[index]*(cnt-i);
                if (take < 0) break;
                int r = (take <= 0) ? target : take;
                if (check(coins, index-1, i, r)) return true;    
            }
        }
        return false;
    }
    
public:
    int coinChange(vector<int>& coins, int amt) {
        if (amt&1){
            short i=0;
            for (; i<coins.size(); i++){
                if (coins[i]&1) break;
            }    
            if (i==coins.size()) return -1;
        }
    
        sort(coins.begin(), coins.end());
        int best = amt/coins.back();
        int worst = amt/coins.front();
        
        for(short i=best; i<=worst;i++){
            if (check(coins, coins.size()-1, i, amt)) return i;
        }
        return -1;
    }
};