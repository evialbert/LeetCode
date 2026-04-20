class Solution {
public:
    bool solve(vector<vector<int>>& grid, int k){
        for(auto i:grid){
            bool t = false;

            for(auto j:i){
                if((j | k) == k){
                t=true;
                break;
                }
            }
        if(!t) return false;
        }
    return true;
    }
    
    int minimumOR(vector<vector<int>>& grid) {
        int res = (1 << 17)-1;

        for(int i=16; i>=0; i--){
            int temp = res & ~(1<<i);

            if(solve(grid, temp)){
                res = temp;
            }
        }
        return res;
    }
};