class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans=0;
        int n=forts.size();
        for (int i=0; i<n; i++){
            if (forts[i]==1){
                i++;
                int curr=0;
                while (i<n && forts[i]==0){
                    curr++;
                    i++;
                }
                if (i<n && forts[i]==-1)ans= max(ans,curr);
                i--;
            }
            if (forts[i]==-1){
                i++;
                int curr=0;
                while (i<n && forts[i]==0){
                    curr++;
                    i++;
                }
                if (i<n && forts[i]==1)ans= max(ans,curr);
                i--;
            }
            
        }
        return ans;
    }
};