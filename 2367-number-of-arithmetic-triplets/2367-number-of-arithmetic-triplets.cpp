class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        unordered_map<int,bool>mp;
        int count=0;

        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }

        for(int i=0;i<n;i++){
            if(mp[nums[i]-diff] && mp[nums[i]+diff]){
                count++;
            }
        }
        return count;
    }
};