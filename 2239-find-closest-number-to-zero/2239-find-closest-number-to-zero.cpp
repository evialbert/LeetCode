class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({abs(nums[i]),nums[i]});
        }
if(pq.top().second<0 && find(nums.begin(),nums.end(),pq.top().first)==nums.end())
        return pq.top().second;
        else
            return pq.top().first;
       
    }
};