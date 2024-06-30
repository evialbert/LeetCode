class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<double>avgs;
        while(nums.size()>0){
            int n=nums.size();
            avgs.push_back((nums[0]+nums[nums.size()-1])/2.0);
            nums.erase(nums.begin()+0);
            nums.pop_back();
        }
        double ans=avgs[0];
        for(int i=0;i<avgs.size();i++) {
            if(ans>avgs[i]) ans=avgs[i];
        }
        return ans;
    }
};