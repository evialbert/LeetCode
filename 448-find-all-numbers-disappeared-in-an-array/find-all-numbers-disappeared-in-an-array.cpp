class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        vector<int> result; 
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]<1){
               result.push_back(i); 
            }
        }
        return result;
    }
};

    