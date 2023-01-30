class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() % 2 == 0 && nums2.size() % 2 == 0) return 0;
        
        int ans = 0, ans1 = 0;
        for(auto &it : nums1){
            ans ^= it;
        }
        
        if(nums1.size() % 2 == 0) return ans;
        
        for(auto &it : nums2){
            ans1 ^= it;
        }
        
        if(nums2.size() % 2 == 0) return ans1;
        
        return ans ^ ans1;
    }
};