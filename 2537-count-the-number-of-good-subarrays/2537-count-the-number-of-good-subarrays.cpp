class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size(),c=0,i=0,j=0;
        long long count=0;
        unordered_map<int,int> mp;
        while(j<n){
            c+=mp[nums[j]];
            mp[nums[j]]++;
            while(c>=k){
                count+=n-j;
                c-=mp[nums[i]]-1;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};