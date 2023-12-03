class Solution {
public:
    vector<int> findPeaks(vector<int>& mount) {
        int n=mount.size();
        vector<int>ans;
        for(int i=1;i<n-1;i++){
            if(mount[i]>mount[i-1] && mount[i]>mount[i+1])
            ans.push_back(i);
        }

        return ans;
    }
};