class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& qr) {

        int pos = 0;
        int n = nums.size();
        vector<int> sweep(n+1,0);
        
        int csum = 0;

        for(int i = 0; i<n; i++){
           
           csum += sweep[i];
           sweep[i] = 0;
           
           if(csum < nums[i]){
              
              if(pos == qr.size()) return -1;

              int l = qr[pos][0];
              int r = qr[pos][1];
              int val = qr[pos][2];
              
              if(r >= i){
              if(l <= i && r>=i) csum += val;
              else sweep[l]+=val;

              sweep[r+1]-=val;}
              pos++;
              i--;
           }
        }
        return pos;

    }
};