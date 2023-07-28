class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> index(queries.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int &A, int &B) {
            return queries[A] < queries[B];
        });
        sort(logs.begin(), logs.end(), [](vector<int> &A, vector<int> &B) {
            return A[1] < B[1];
        });
        unordered_map<int, int> Map;
        vector<int> ans(queries.size());
        int start = 0, end = 0;
        for(int i: index) {
            while(end < logs.size() && logs[end][1] <= queries[i]) {
                Map[logs[end++][0]]++;
            }
            while(start < logs.size() && logs[start][1] < queries[i] - x) {
                Map[logs[start][0]]--;
                if(!Map[logs[start][0]]) Map.erase(logs[start][0]);
                start++;
            }
            ans[i] = n - Map.size();
        }
        return ans;
    }
};