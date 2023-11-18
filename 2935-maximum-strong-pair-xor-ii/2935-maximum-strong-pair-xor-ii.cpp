class Solution {
public:
    int son[1000000][2];
    int idx = 0;
    
    void add(int k) {
        int ptr = 0;
        for (int i = 20; i >= 0; i--) {
            int b = (k >> i) & 1;
            if (!son[ptr][b]) son[ptr][b] = ++idx;
            ptr = son[ptr][b];
        }
    }
    
    int query(int k) {
        int ptr = 0;
        int ans = 0;
        bool tight = true;
        for (int i = 20; i >= 0; i--) {
            int b = (k >> i) & 1;
            if (son[ptr][1 - b] && (!tight || b == 1)) {
                tight = false;
                ptr = son[ptr][1 - b];
                ans += (1 << i);
            } else {
                ptr = son[ptr][b];
            }
        }
        return ans;
    }
    
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        
        int n = nums.size();
        int i = n-1, j = n-1;
        for (; j >= 0; j--) {
            while (i >= 0 && nums[j] <= 2 * nums[i]) {
                add(nums[i--]);
            }
            ans = max(ans, query(nums[j]));
        }
        return ans;
    }
};