class Solution {
public:
    typedef long long ll;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {

        ll ans = 0, sum=0;
        int M=1e9+7;
        vector<pair<int,int>>v; // stores (eff, speed) in sorted order

        //stores max k elements with eff greater than curr index and max speeds that are possible
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;i++){
            v.push_back({eff[i], speed[i]});
        }
        sort(v.begin(),v.end());

        for(int i=n-1;i>=0;i--){
            if(pq.size()>=k){
                sum -= pq.top().first;
                pq.pop();
            }
            sum += v[i].second;
            pq.push({v[i].second,v[i].first});
            ans = max(ans,sum*v[i].first);
        }
        return ans%M;
    }
};