class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int> mp;
        for(auto it:meetings){
            mp[it[0]]+=1;
            mp[it[1]]+=-1;
        }
        int curr=0,ans=0,prev=1;
        for(auto it:mp){
            if(curr==0){
                ans+=it.first-prev;
                prev=it.first+1;
                curr+=it.second;
            }
            else{
                prev=it.first+1;
                curr+=it.second;
            }
        }
        ans+=days-prev+1;
        return ans ;
    }
};