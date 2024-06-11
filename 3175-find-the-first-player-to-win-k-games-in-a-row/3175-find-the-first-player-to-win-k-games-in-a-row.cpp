class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        
        int maxi = skills[0]; //Temporary maximum element
        int ans = 0; //Temporary index of winner;
        int cnt = 0; //cnt of consecutivines
        if(k>=n) return max_element(skills.begin(),skills.end())-skills.begin();
        else{
            for(int i=1;i<n;i++){
               if(skills[i]>maxi){
                maxi = skills[i];
                ans = i;
                cnt = 1;
               }else{
                cnt++;
               }

               if(cnt==k){
                break;
               }
            }
        }

        return ans;
    }
};