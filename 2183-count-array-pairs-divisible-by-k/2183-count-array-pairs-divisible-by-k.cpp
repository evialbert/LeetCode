class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> numFactor;
        for(int i=1;i<=sqrt(k+1);i++) 
            if(k % i == 0) numFactor[i], numFactor[k/i];
        long long res = 0;
        for(auto x:nums){
            int y = k/gcd(x,k);
            res += numFactor[y];            
            for(auto& [factor, n] : numFactor)  
                if(x%factor == 0) n++;
        }
        return res;
    }
};