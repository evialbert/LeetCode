class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        vector<vector<int>> result;

        int min_v = numeric_limits<int>::max();
        unordered_set<char> sс;
        for (const string& word : words) {
            for (auto c : word) {
                sс.insert(c);
            }
        }

        unordered_map<char, int> mp;
        unordered_map<int, char> rev_mp;
        int count = 0;
        for (auto c : sс) {
            mp[c] = count;
            rev_mp[count++] = c;
        }
        vector<vector<int>> adj(count, vector<int>(count, 0));
        vector<int> in_degree(count, 0);
        vector<int> ones(count, false);
        for (int mask = 0; mask < (1 << count); ++mask) {
            fill(in_degree.begin(), in_degree.end(), 0);
            fill(ones.begin(), ones.end(), false);
            for (int i = 0; i < count; i++) fill(adj[i].begin(), adj[i].end(), 0);

            for (int j = 0; j < count; j++) {
                if ((mask & (1 << j)) != 0) {
                    ones[j] = 1;
                }
            }

            for (const string& word : words) {
                const auto u = mp[word[0]], v = mp[word[1]];
                if (ones[u] && ones[v]) {
                    adj[u][v] = 1;
                    in_degree[v]++;
                }
            }

            queue<int> q;
            for (int i = 0; i < count; i++) {
                if (in_degree[i] == 0) q.push(i);
            }

            int visited = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                visited++;
                for (int i = 0; i < count; i++) {
                    if (adj[node][i] == 1) {
                        in_degree[i]--;
                        if (in_degree[i] == 0) q.push(i);
                    }
                }
            }

            if (visited == count) {
                vector<int> r(26, 0);

                int curr = 0;
                for (int i = 0; i < count; i++) {
                    r[rev_mp[i] - 'a'] = 2 - ones[i];
                    curr += 2 - ones[i];
                }

                if (curr < min_v) {
                    result = { r };
                    min_v = curr;
                } else if (curr == min_v){
                    result.emplace_back(std::move(r));
                }
            }
        }

        return result;
    }
};