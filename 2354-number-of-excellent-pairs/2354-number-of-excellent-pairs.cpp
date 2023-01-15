class Solution {
    long long int Count(int n)
    {
        long long int count = 0;
        while(n) 
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int> sum;
        long long int ans = 0;
        for(int i = 0; i < n; i++)
        {
            um[nums[i]] = 1;
        }
        for(auto &[fst,_] : um)
        {
            sum.push_back(Count(fst));
        }
        sort(sum.begin(), sum.end());
        int i = 0, j = sum.size()-1;
        while(i <= j)
        {
            if(sum[i] + sum[j] >= k)
            {
                ans += 2*(j - i) + 1;
                j--;
            }
            else
                i++;
        }
        return ans;
    }
};