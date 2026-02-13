class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        long long res=0;
        vector<pair<long long, int>> loss(n);

        for(int i=0; i<n; i++){
            loss[i]={(long long)technique2[i]-technique1[i], i};
        }
        sort(loss.begin(), loss.end());

        vector<bool> used(n, false);

        for(int i=0; i<k; i++){
            int idx=loss[i].second;
            used[idx]=true;
            res+=technique1[idx];
        }

        for(int i=0; i<n; i++){
            if(!used[i]){
                res+=max(technique1[i], technique2[i]);
            }
        }

        return res;
    }
};