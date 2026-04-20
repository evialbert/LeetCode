class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        map<int, int> mp1, mp2;

        // cnt --> counts the number of distinct elements in the subarray having frequency >= m
        int i1 = 0, i2 = 0, cnt = 0;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            mp1[nums[j]]++;
            mp2[nums[j]]++;
            if (mp2[nums[j]] == m) cnt++;
            while (mp1.size() > k) {
                mp1[nums[i1]]--;
                if (mp1[nums[i1]] == 0)
                    mp1.erase(nums[i1]);
                i1++;
            }
            while (cnt >= k) {
                mp2[nums[i2]]--;
                if (mp2[nums[i2]] == m-1)
                    cnt--;
                if (mp2[nums[i2]] == 0)
                    mp2.erase(nums[i2]);
                i2++;
            }
            if (i2 > i1)
                ans += (i2-i1);
        }
        return ans;
    }
};