class Solution {
public:
int bfs(vector<int>& start, vector<int>& target) {
    if (start == target) return 0;

    unordered_set<string> visited; 
    queue<pair<vector<int>, int>> q; 

    auto serialize = [](const vector<int>& v) {
        string s;
        for (int x : v) s += to_string(x) + ",";
        return s;
    };

    q.push({start, 0});
    visited.insert(serialize(start));

    while (!q.empty()) {
        auto [curr, steps] = q.front(); q.pop();
        int n = curr.size();

        for (int L = 0; L < n; L++) {
            for (int R = L; R < n; R++) {
                vector<int> rem;
                rem.insert(rem.end(), curr.begin(), curr.begin()+L);
                rem.insert(rem.end(), curr.begin()+R+1, curr.end());

                vector<int> sub(curr.begin()+L, curr.begin()+R+1);

                for (int pos = 0; pos <= rem.size(); pos++) {
                    vector<int> next = rem;
                    next.insert(next.begin()+pos, sub.begin(), sub.end());

                    if (next == target) return steps + 1;

                    string key = serialize(next);
                    if (!visited.count(key)) {
                        visited.insert(key);
                        q.push({next, steps + 1});
                    }
                }
            }
        }
    }

    return -1; 
}

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<string,int> visited;
        return bfs(nums1,nums2);
    }
};