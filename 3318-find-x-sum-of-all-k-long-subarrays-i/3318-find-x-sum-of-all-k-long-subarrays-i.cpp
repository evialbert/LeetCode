class Solution {
public:
    unordered_map<int, int> mp;
    static bool compare(pair<int, int>& a, pair<int,int>& b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
    int solve(vector<int>& nums, int left, int right, int x)
    {
        if(mp.size() != 0) 
            mp.clear();

        for(int i=left; i<=right; i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> res(mp.begin(), mp.end());

        sort(begin(res), end(res), compare);
        int answer = 0, count = 0;
        for(auto it: res)
        {
            if(count != x)
            {
                answer += (it.first * it.second);
                count++;
            }
        }

        return answer;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans ;
        int n = nums.size();
        int left = 0;
        int right = k-1;
        while(right < n)
        {
            int sum = solve(nums, left, right, x);
            ans.push_back(sum);
            left++;
            right++;
        }
        return ans ;
    }
};