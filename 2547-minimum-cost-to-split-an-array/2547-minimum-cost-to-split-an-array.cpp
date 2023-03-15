class Solution {
    int mem[1001]{};
    int k;
public:
    int partition(vector<int>& nums, int idx){
        if(idx >= nums.size()) return 0;
        auto& ret = mem[idx];
        if(ret != -1) return ret;
        unordered_map<int, int> freq{};
        int ans = INT_MAX;
        int sum = 0;
        for(int i = idx; i < nums.size(); ++i){
            auto& numFreq = freq[nums[i]];
            ++numFreq;
            if(numFreq > 1) sum += (numFreq == 2) ? 2 : 1;
            ans = min(ans, sum + k + partition(nums, i+1));
        }
        return ret = ans;
    }
    int minCost(vector<int>& nums, int _k) {
        memset(mem, -1, sizeof mem);
        k = _k;
        return partition(nums, 0);
    }
    
};