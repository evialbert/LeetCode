class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> next(n, n);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && (nums[s.top()] % k) != (nums[i] % k)){
                next[s.top()] = i;
                s.pop();                
            }
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            nums[i] /= k;
        }
        vector<vector<int>> old = queries;
        int B = sqrt(n);
        map<pair<int,int>, long long> mp;
        sort(queries.begin(), queries.end(), 
            [&](const auto &a, const auto &b){
                if(a[0] / B != b[0] / B) return a[0] / B < b[0] / B;
                return a[1] < b[1];
            }
        );
        long long sum_left = 0; long long sum_right = 0;
        multiset<int> left; multiset<int> right;
        auto rebalance = [&]() {
            if(left.size() > right.size() + 1){
                auto it = prev(left.end());
                long long x = *it;
                sum_left -= x;
                left.erase(it);
                right.insert(x);
                sum_right += x;
            }
            else if(right.size() > left.size()){
                auto it = right.begin();
                long long x = *it;
                sum_right -= x;
                right.erase(it);
                left.insert(x);
                sum_left += x;
            }
        };
        auto add = [&](int x){
            if(left.empty() || x <= *left.rbegin()){
                left.insert(x);
                sum_left += x;
            } else {
                right.insert(x);
                sum_right += x;
            }
            rebalance();
        };
        auto erase = [&](int x){
            if(!left.empty() && x <= *left.rbegin()){
                auto it = left.find(x);
                sum_left -= x;
                left.erase(it);
            } else {
                auto it = right.find(x);
                sum_right -= x;
                right.erase(it);
            }
            rebalance();
        };
        int L = 0; int R = -1;
        vector<long long> answer;
        for(auto &q : queries){
            int l = q[0]; int r = q[1];
            if(next[l] <= r){
                // cout << l << " " << r << " here\n";
                mp[{l, r}] = -1;
                continue;
            }
            while(R < r){
                add(nums[R + 1]);
                R++;
            }
            while(L > l){
                add(nums[L - 1]);
                L--;
            }
            while(R > r){
                erase(nums[R]);
                R--;
            }
            while(L < l){
                erase(nums[L]);
                L++;
            }
            long long median = *left.rbegin();
            long long cost = median * (long long)left.size() - sum_left + sum_right - median * (long long)right.size();
            mp[{l, r}] = cost;
        }
        for(auto &q : old){
            answer.push_back(mp[{q[0], q[1]}]);
        }
        return answer;
    }
};