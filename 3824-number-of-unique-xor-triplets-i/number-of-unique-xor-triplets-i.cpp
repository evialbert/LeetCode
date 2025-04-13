class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        
        int m = 0;
        
        while((1 << (m + 1)) <= n) {
            m++;
        }
    
        return 1 << (m + 1);
    }
};