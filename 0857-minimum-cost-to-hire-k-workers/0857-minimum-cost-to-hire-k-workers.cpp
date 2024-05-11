class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>ratio;
        int n = quality.size();
        for(int i =0;i<n;i++) ratio.emplace_back(static_cast<double>(wage[i]) / quality[i],quality[i]);
        sort(begin(ratio),end(ratio)); // sort as per the ratio
        priority_queue<int>pq;
        int sum=0;double mx=0.0,ans=DBL_MAX;
        for(auto i: ratio){
            mx = i.first;
            sum+=i.second;
            pq.push(i.second);
            if(pq.size()>k) sum-=pq.top(),pq.pop(); // remove low yielding worker
            if(pq.size()==k) ans=min(ans,sum*mx);
        }
        return ans;
        
    }
};