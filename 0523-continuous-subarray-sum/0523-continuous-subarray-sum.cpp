class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        umap[nums[0]%k] = 0;
        umap[0] = -1;
        for(int i=1; i<nums.size(); i++){
            nums[i] = (nums[i] + nums[i-1])%k;
        }
        for(int i=1; i<nums.size(); i++){
            if(umap.find(nums[i]) != umap.end()){
                if(i-umap[nums[i]]>1)
                    return true;
            }else umap[nums[i]] = i;
        }
        return false;
    }
};