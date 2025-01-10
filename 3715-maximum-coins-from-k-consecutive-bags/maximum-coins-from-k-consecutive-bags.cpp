class Solution {
public:

    long long window (vector<pair<long long,long long>>& v, int k) {
      int n = v.size();
      int left = 0, right = 0, len = 0;
      long long res = 0ll, ans = 0ll;
      while (left < n && right < n) {
        
        if (len +  v[right].first <= k) {
          len += v[right].first;
          ans += v[right].first * v[right].second;
          res = max(res, ans);
          right++;
        }
        else {
          res = max(res, ans + (abs(len - k) * v[right].second));
          ans -= v[left].first * v[left].second;
          len -= v[left].first;
          left++;
        }
        
      }
      return res;
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) {

      // check for all start indexes and end indexes
      ios::sync_with_stdio(false);
      cin.tie(0); cout.tie(0);
      
      sort(coins.begin(), coins.end());
      int n = coins.size();
      int gap = 0;
      vector<pair<long long,long long>> v;
      for (int i = 0; i < n; i++) {
        int val = coins[i][2];
        int dis = coins[i][1] - coins[i][0] + 1;
        if (i > 0)
          gap = coins[i][0] - coins[i - 1][1] - 1;
        if (gap != 0)
          v.push_back({gap * 1ll, 0ll});

        v.push_back({dis * 1ll, val * 1ll});
      }

      //forward check
      long long res = window(v, k);
      //reverse check
      reverse(v.begin(), v.end());
      res = max(res, window(v, k));

      return res;
    }
};