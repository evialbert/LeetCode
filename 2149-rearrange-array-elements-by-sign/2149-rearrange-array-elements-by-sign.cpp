class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int >ans(n,0);
        int evenIndex =0 ,oddInd=1;
        for(auto x :nums){
            if(x>0){
                ans[evenIndex]=x;
                evenIndex+=2;
            }else if( x<0){
                ans[oddInd]=x;
                oddInd+=2;
            }
        }
        return ans;
    }
};