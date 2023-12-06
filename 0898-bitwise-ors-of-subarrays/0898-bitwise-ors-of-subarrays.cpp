class Solution {
    typedef long long ll;
public:
    int subarrayBitwiseORs(vector<int>& v) {
        unordered_set<ll>ans, pre;
        for (ll it : v) {
            unordered_set<ll>cur;
            for (ll ti : pre) {
                cur.insert(ti | it);
                ans.insert(it | ti);
            }
            cur.insert(it);
            ans.insert(it);
            pre = cur;
        }
        return ans.size();
    }
};