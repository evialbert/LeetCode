class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        sort(q.begin(),q.end(),comp);
        vector<int>t(nums.size(),0);
        priority_queue<int>l;
        int tn=0;
        int in=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=max(0,nums[i]-tn);
            while(in<q.size() && q[in][0]==i){
                l.push(q[in][1]);
                in++;
            }
            while(nums[i] && !l.empty() && l.top()>=i)nums[i]--,tn++,t[l.top()]++,l.pop();
            if(nums[i])return -1;
            tn-=t[i];
        }
        return l.size();
    }
};