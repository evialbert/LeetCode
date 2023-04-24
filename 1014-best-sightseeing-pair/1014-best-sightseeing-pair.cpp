class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        
        int n = arr.size();
      
        int maxi = INT_MIN;
        
        // left_max will keep track of max. value of (arr[i] + i)
        
        int left_max = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            // find sum
            
            int sum = left_max + arr[i] - i;
            
            // update maxi
            
            maxi = max(maxi, sum);
            
            // update left_max
            
            left_max = max(left_max, arr[i] + i);
        }
        
        return maxi;
    }
};