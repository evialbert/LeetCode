class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     vector<pair<int,int>> p;
        for(int i=0;i<nums1.size();i++){
            p.push_back({nums2[i],nums1[i]});
            
        }
        sort(p.begin(),p.end());
        long long ans=0;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=nums1.size()-1;i>=0;i--){
            sum+=p[i].second;
            pq.push(p[i].second);
            if(pq.size()>k){
                sum=sum-pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans,sum*p[i].first);
            }
        }
        return ans;
    }
};