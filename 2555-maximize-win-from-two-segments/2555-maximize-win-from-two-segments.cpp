class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        int mx = 1;
        int n = nums.size();
        vector<int> right(n,1);
        for(int i=0; i<n; ++i){
            auto idx = upper_bound(begin(nums),end(nums),nums[i]+k) - begin(nums) - 1;
            right[i] = idx-i+1;
        }
        vector<int> mxright(n,1);
        for(int i=n-2; i>=0; --i){
            mxright[i] = max(right[i],mxright[i+1]);
        }
        for(int i=0; i<right.size(); ++i){
            int idx = i + right[i];
            int s = right[i];
            if(idx<n)
                s += mxright[idx];
            mx = max(mx,s);
        }
        return mx;
    }
};