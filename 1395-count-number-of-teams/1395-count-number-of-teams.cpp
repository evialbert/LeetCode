class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int leftSmaller = 0, leftGreater = 0, rightSmaller = 0, rightGreater = 0;
            for(int j=i-1; j>=0; j--){
                if(rating[j] < rating[i]) leftSmaller++;
                else leftGreater++;
            }
            for(int j=i+1; j<n; j++){
                if(rating[j] < rating[i]) rightSmaller++;
                else rightGreater++;
            }
            ans += (leftSmaller * rightGreater + leftGreater * rightSmaller); 
        }
        return ans;
    }
};