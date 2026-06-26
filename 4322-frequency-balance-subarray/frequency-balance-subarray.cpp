class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans = 1;

         for (int i = 0; i < nums.size(); i++) {
            unordered_map<int,int> mp;
            unordered_map<int,int> mp1;

            for (int j = i; j < nums.size(); j++) {
                int x = nums[j];

                if (mp.count(x)) {
                    mp1[mp[x]]--;
                    if (mp1[mp[x]] == 0)
                        mp1.erase(mp[x]);
                }

                mp[x]++;
                mp1[mp[x]]++;

                if (mp.size() == 1) {
                    ans = max(ans, j - i + 1);
                    continue;
                }

                if (mp1.size() != 2) continue;

                auto it = mp1.begin();
                int f1 = it->first;
                ++it;
                int f2 = it->first;

                int small = min(f1, f2);
                int large = max(f1, f2);

                if (large == 2 * small) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};