class Solution {
public:

    map< pair<int,int>, pair<long long, vector<int>> >dp;
    
    pair<long long, vector<int>> solve(vector<vector<int>>& v, int taken, int idx) {
        
        int n = v.size();
        
        if(idx >= n || taken == 4) {
            return {0, {}};
        }

        if(dp.find({idx, taken}) != dp.end()) {
            return dp[{idx, taken}];
        }

        pair<long long, vector<int> >ans1 = solve(v, taken, idx + 1);

        int nextIdx = n;
        int left = idx;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(v[mid][0] > v[idx][1]) {
                nextIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        pair<long long, vector<int> >ans2 = solve(v, taken + 1, nextIdx);
        ans2.first += v[idx][2];
        ans2.second.push_back(v[idx][3]);
        sort(ans2.second.begin(), ans2.second.end());

        pair<long long, vector<int> >ans;
        if(ans1.first > ans2.first) {
            ans = ans1;
        } else if(ans2.first > ans1.first) {
            ans = ans2;
        } else {
            ans.first = ans1.first;
            ans.second = min(ans1.second, ans2.second);
        }

        return dp[{idx, taken}] = ans;

    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>v;
        for(int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            int wt = intervals[i][2];
            v.push_back({l, r, wt, i});
        }
        sort(v.begin(), v.end());
        pair<long long, vector<int> >ans = solve(v, 0, 0);
        return ans.second;        
    }
};