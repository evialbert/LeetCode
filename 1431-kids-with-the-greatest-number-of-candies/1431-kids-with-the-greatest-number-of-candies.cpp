class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        if(n==0) return {};
        
        vector<bool> result(n, false);
        
        int max_val=INT_MIN;
        for(int i=0; i<n; i++)
            max_val=max(max_val, candies[i]);
        
        for(int i=0; i<n; i++)
            if(candies[i]+extraCandies >= max_val)
                result[i]=true;
        
        return result;
    }
};