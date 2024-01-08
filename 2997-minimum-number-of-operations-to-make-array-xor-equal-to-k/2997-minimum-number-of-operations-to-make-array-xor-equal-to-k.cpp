class Solution {
public:
    int minOperations(vector<int>& nums, int k){
        int result=0, n=nums.size(), currXOR=0, temp=0;
        for(int i=0;i<n;i++) currXOR^=nums[i];
        temp=currXOR^k;
        while(temp!=0){
            result+=(temp&1);
            temp=temp>>1;
        }
    return result;
    }
};