class Solution {
public:    
    long long distributeCandies(int n, int limit) {

        long long ans=0;
        for (int i=limit; i>=0; i--) {
            int rem = n-i;
            
            int maxs = min(limit, rem);
            int mins = max(0, rem-limit);
            
            ans+=max(0, (maxs-mins)+1);
            
            
        }
        return ans;
        
    }
};