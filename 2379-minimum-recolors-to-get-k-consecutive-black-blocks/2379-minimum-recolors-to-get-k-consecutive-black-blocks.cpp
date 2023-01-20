class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX, i=0;
        while(i<=blocks.size()-k){
            int cnt= count(blocks.begin()+i,blocks.begin()+i+k,'W');
            ans= min(ans,cnt);
            i++;
        }                
        return ans;
    }
};