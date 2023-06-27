class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<min((int)nums1.size(),k);i++)
        {
            for(int j=0;j<min((int)nums2.size(),k);j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else
                    break;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};