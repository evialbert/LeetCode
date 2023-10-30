class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int sum1 = 0,sum2 = 0;
        int ct0_1 = 0,ct0_2 = 0;
        for(int i:nums1){
            sum1 += i;
            if(i == 0){
                ct0_1++;
            }
        }
        for(int j:nums2){
            sum2 += j;
            if(j == 0){
                ct0_2++;
            }
        }
        if(ct0_1 == 0 && (sum1 < sum2+ct0_2) || ct0_2 == 0 && (sum2 < sum1 + ct0_1)) return -1;

        return max((sum1+ct0_1),(sum2+ct0_2));
    }
};