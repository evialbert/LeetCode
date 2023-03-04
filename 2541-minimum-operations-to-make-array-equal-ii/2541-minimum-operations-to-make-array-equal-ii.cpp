class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long int in = 0, d = 0;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]==nums2[i])continue;
            if(k==0)return -1;
            int x = abs(nums1[i]-nums2[i]);
            if(x%k)return -1;
            if(nums1[i]>nums2[i]){
                in += (x/k);
            }else{
                d += (x/k);
            }
        }
        if(in==d)return in;
        
        return -1;
    }
};