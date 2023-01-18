class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int nxt = nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            int x = nums[i];
            int parts = (x+nxt-1)/nxt;   // used for ceil(x/nxt)
            res += parts-1;
            nxt = x/parts;
        }
        return res;
    }
};