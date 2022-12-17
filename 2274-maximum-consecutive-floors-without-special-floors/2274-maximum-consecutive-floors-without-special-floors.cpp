class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int n = special.size();
        map<int,int> mp;
        int ans=0;
        for(int i=0; i<n; i++) mp[special[i]]++;
        if(!mp.count(special[0]-1) && special[0]-1 >=bottom) {
            ans=max(ans,abs(special[0]-bottom));
        }
        for(int i=0; i<n-1; i++) {
            if(!mp.count(special[i]+1) && !mp.count(special[i+1]-1) && special[i]+1<=special[i+1]-1) {
                 ans=max(ans,abs((special[i]+1)-(special[i+1]-1))+1);
            }
        }
        if(special.back()+1<=top) ans=max(ans,abs(top-(special.back()+1))+1);
        return ans; 
    }
};