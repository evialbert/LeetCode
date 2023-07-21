class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans;

        while(n--)
        {
            int diff = sums[1] - sums[0];
            unordered_map<int, int> freq;
            vector<int>s1, s2;
            bool flag = false;
            for(auto &it:sums)
            {
                if(!freq[it])
                {
                    s1.push_back(it);
                    freq[it + diff]++;
                    if(it == 0) flag = true;
                }
                else
                {
                    s2.push_back(it);
                    freq[it]--;
                }
            }
            if(flag)
            {
                ans.push_back(diff);
                sums = s1;
            }
            else
            {
                ans.push_back(-diff);
                sums = s2;
            }
        }

        return ans;
    }
};