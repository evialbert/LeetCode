class Solution {
public:
    static long long minOperations(vector<int>& nums) {
        long long sum=0;
        int prev=0;
        for(int x: nums){
            sum+=max(0, prev-x);
            prev=x;
        }
        return sum;
    }
};