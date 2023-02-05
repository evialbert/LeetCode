class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0,cnt=0;
        for(auto it : nums){
            if(it%2==0 && it%3==0){
                sum += it;
                cnt+=1;
            }
        }
        return cnt!=0?sum/cnt:0;
    }
};