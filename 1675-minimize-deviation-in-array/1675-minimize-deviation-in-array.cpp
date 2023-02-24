class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        vector<int>v(nums);
        priority_queue<int>p;
        for(auto &x:nums){
            if(x&1)x*=2;
            p.push(x);
        }
        int mn=*min_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(!p.empty()){
            int n=p.top();
            ans=min(ans,n-mn);
            p.pop();
            if(n%2==0){
                mn=min(mn,n/2);
                p.push(n/2);
            }
            else{
                break;
            }
        }
        return ans;
    }
};