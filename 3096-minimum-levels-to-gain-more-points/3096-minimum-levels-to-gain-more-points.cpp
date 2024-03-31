class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum1=0,sum2=0;
        for(auto it:possible){
            if(it==1) sum1++;
            else sum1--;
        }
        int i=possible.size()-1,j=possible.size()-1,ans=INT_MAX;
        while(i>0){
            if(possible[i]==0){
                sum1++;
            }else{
                sum1--;
            }
            i--;
            if(possible[j]==0){
                sum2--;
            }else{
                sum2++;
            }
            j--;
            if(sum1>sum2){
                ans=min(ans,i+1);
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
};