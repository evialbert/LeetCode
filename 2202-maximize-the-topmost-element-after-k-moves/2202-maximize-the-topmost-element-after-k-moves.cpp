class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
   
        //if no moves given first element is max element
        if(k == 0) return nums[0];
        
        //if size is one we can remove one element and insert one element only when k is even
        if(k %2 != 0 && nums.size()==1) return -1;
        
        int n = nums.size();
        int i=0, maxm = 0;
        
        // Remove top k-1 elements and find maxm out of them
        while(i < n && i < k-1){
            maxm = max(maxm, nums[i]);
            i++;
        }
        
        int ans = 0;
        
        //We choose best from two options 
        //either remove k elements (k+1th is maxm) or remove k-1 elements then insert maxm element (maxm element lies in [0,k-1])
        if(k < n) ans = nums[k];
        return max(maxm, ans);
    }
};