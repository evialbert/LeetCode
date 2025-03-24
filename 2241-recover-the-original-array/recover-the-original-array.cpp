class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n=nums.size(),a=INT_MAX,b=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            int k=(nums[i]-nums[0])%2==1 ? -1:(nums[i]-nums[0])/2;
            if(k<=0) continue;

            map<int,int> mp;
            vector<int> v;
            for(int j=0;j<n;j++){
                if(mp.find(nums[j])!=mp.end()){
                    v.push_back(nums[j]-k);
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0) mp.erase(nums[j]);
                } else {
                    mp[nums[j]+2*k]++;
                }
            }

            if(v.size()==n/2 && mp.size()==0) return v;
        }

        return {};
    }
};