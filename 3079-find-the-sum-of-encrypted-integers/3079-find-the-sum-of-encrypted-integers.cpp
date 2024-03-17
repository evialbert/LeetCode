class Solution {
public:
    
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(auto temp:nums){
            int c=0,maxi=0;
            while(temp){
                c++;
                if(maxi<temp%10)
                    maxi=temp%10;
                temp/=10;
            }
            int num=0;
            while(c--){
                num=(num*10)+maxi;
            }
            ans+=num;
        }
        return ans;
    }
};