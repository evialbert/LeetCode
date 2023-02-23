class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       
        priority_queue<pair<int,int>>pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq2;
        int n = profits.size();
        k = min(k,n);
        for(int i=0;i<n;i++)
        {
            if(capital[i]<=w) pq1.push({profits[i],capital[i]});
            else pq2.push({capital[i], profits[i]});
        }
        while(k && pq1.size())
        {
            w+=pq1.top().first;
            pq1.pop();
            while(pq2.size() && pq2.top().first<=w)
            {
                pair<int,int>p = pq2.top();
                pq2.pop();
                pq1.push({p.second, p.first});
            }
            k--;
        }
        return w;
    }
};