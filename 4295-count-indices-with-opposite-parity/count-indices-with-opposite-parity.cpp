class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            if(nums[i]%2==0){
                for(int j=i+1;j<n;j++){
                    if( nums[j] %2 !=0){
                        count++;
                    }
                }
                ans.push_back(count);
            }
            else{
                for(int j=i+1;j<n;j++){
                    if( nums[j] %2 ==0){
                        count++;
                    }
                }
                ans.push_back(count);
            }
        }
        return ans;
    }
};