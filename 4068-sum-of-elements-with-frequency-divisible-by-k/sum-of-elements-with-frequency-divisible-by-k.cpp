class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second % k == 0){
                int x = it.first * it.second;
                sum += x;
            }
        }

        return sum;
    }
};