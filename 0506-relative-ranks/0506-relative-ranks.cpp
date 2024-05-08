class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int i=0;
        for(auto &it: score) pq.push({it,i++});
        vector<string> ans(score.size());
        if(pq.size()>0){ ans[pq.top().second] = "Gold Medal"; pq.pop();}
        if(pq.size()>0){ ans[pq.top().second] = "Silver Medal"; pq.pop();}
        if(pq.size()>0){ ans[pq.top().second] = "Bronze Medal"; pq.pop();}
        int r = 4;
        while(!pq.empty()){
            ans[pq.top().second] = to_string(r++);
            pq.pop();
        }
        return ans;
    }
};