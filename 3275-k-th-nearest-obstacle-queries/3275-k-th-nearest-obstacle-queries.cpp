class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> results;
        
        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int distance = abs(x) + abs(y);
            
            if (pq.size() < k) {
                pq.push(distance);
            } else if (distance < pq.top()) {
                pq.pop();
                pq.push(distance);
            }
            
            if (pq.size() < k) {
                results.push_back(-1);
            } else {
                results.push_back(pq.top());
            }
        }
        
        return results;
    }
};
