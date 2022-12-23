class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> requiredRocks(n);
        for(int i=0;i<n;i++) {
            requiredRocks[i] = capacity[i] - rocks[i];
        }
        sort(requiredRocks.begin(),requiredRocks.end());
        int full = 0;
        for(int i=0;i<n and additionalRocks>0;i++) {
            if(requiredRocks[i] != 0) {
                if(additionalRocks >= requiredRocks[i])
                    full++;
                
                additionalRocks = additionalRocks-requiredRocks[i];
            } else full++;
        }
        return full;
    }
};