class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& id, int k) {
        vector<int> ans(k);
        unordered_set<string_view> p(begin(pf), end(pf)), n(begin(nf), end(nf));
        using Pii = pair<int, int>;
        priority_queue<Pii> pq;
        for (int i = 0; i < size(report); i++) {
            stringstream ss(report[i]);
            string s;
            int points = 0;
            while (ss >> s) {
                if (p.count(s)) points += 3;
                else if (n.count(s)) points--;
            }
            pq.emplace(-points, id[i]);
            if (pq.size() > k) pq.pop();
        }
        for (int i = k-1; i >= 0; i--) {
            ans[i] = pq.top().second, pq.pop();
        }
        return ans;
    }
};