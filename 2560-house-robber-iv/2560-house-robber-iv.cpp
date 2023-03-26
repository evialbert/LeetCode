class Solution {
    bool isPossible(int maxNum, int k, vector<int>& nums) {
        int t = 0;
        int pp = 0, p = 0; // pp - max number of houses we can rob which is not adjacent to curr element, p - max number of houses if we include adjacent.
        if (nums[0] <= maxNum) p = 1; // we can rob one house
        else p = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int curr = p;
            if (nums[i] <= maxNum) {
                curr = max(pp + 1, p);
            } 
            
            if (curr == k) return true;
            pp = p;
            p = curr;
        }
        return max(pp, p) >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {   
        int n = nums.size();
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isPossible(copy[mid], k, nums)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return copy[l];
    }
};