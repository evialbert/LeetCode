class Solution
{
    public:
        int minimumDeletions(string word, int k)
        {
            unordered_map<char, int> mp;
            vector<int> arr;
            int ans = INT_MAX;

            for (auto x: word)
                mp[x]++;

            for (auto x: mp)
                arr.push_back(x.second);

            sort(arr.begin(), arr.end());

            int maxFreq = arr[arr.size() - 1], minFreq = arr[0];

            for (int i = minFreq; i <= maxFreq; i++)
            {
                int tempMinAns = 0;
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[j] < i)
                        tempMinAns += arr[j];
                    else if (arr[j] > i + k)
                        tempMinAns += arr[j] - (i + k);
                }

                ans = min(ans, tempMinAns);
            }

            return ans;
        }
};