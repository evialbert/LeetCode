class Solution {
public:
    int check(int st, int en, vector<vector<int>>& pref, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int count = pref[en][i] - (st > 0 ? pref[st-1][i] : 0);
            if (count == en - st + 1) {
                ans |= (1 << i);
            }
        }
        return ans;
    }

    int func(vector<vector<int>>& pref, int end, int start, int k) {
        int low = start;
        int high = end;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int rem = check(mid, end, pref, k);
            if (rem == k) {
                ans = max(ans, mid);
                low = mid + 1;
            } else if (rem > k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        long long ans = 0;
        int n = nums.size();
        vector<vector<int>> pref(n, vector<int>(31, 0));

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                pref[i][j] = (i > 0 ? pref[i - 1][j] : 0) + ((nums[i] & (1 << j)) != 0 ? 1 : 0);
            }
        }

        map<int, int> mp;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            if ((nums[i] & k) == k) {
                int an = func(pref, i, prev, k);
                cout<<i<<" "<<an<<endl;
                if (an != -1) {

                    if (mp.find(an) == mp.end()) {
                        mp[an] = i;
                    }
                }
            } else {
                for (auto it : mp) {
                    ans += (it.first - prev + 1) * (i- it.second);
                    prev=it.first+1;
                }
                mp.clear();
                prev = i + 1;
            }
        }

       
        for (auto it : mp) {
            ans += (it.first - prev + 1) * (n - it.second);
            prev=it.first+1;
        }

        return ans;
    }
};