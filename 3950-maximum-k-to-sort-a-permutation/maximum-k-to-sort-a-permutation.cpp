class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        const unsigned n=nums.size();
        int k0=bit_ceil(n)-1, k=k0;// all bits are set
        for(int i=0; i<n; i++){
            const int x=nums[i];
            if (x!=i) k&=x;
        }
        return k==k0?0:k;
    }
};