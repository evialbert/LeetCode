class Solution {
public:
    int binsearch(vector <int>& a,int l, int h, int x) {
            while (l <= h) {
                int mid = (l + h) /2;
                if (a[mid] >= x) {
                    h = mid - 1;
                    if (h < 0) return h + 1;
                    if (a[h] < x) return h+1;
                } else {
                    l = mid + 1;
                }
                
            }
            return -1;
        }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), x, ind;
        for (int i = 1; i < n; i++) nums[i] = nums[i] + nums[i-1];
        if (nums[n-1] < target) return 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            x = i == 0 ? target : target + nums[i-1];
            ind = binsearch(nums, i, n-1, x);
            if (ind != -1) mn = min(mn, ind - i + 1);
        }
        return mn;
        
    }
};