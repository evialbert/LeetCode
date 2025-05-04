class Solution {
public:
    void helper(vector<vector<int>> &ans,int i,int i_,int j,int j_,int &num){
        // if(i > i_ || j > j_) return;
        if(i_ == i && j_ == j){
            ans[i][j] = num;
            num--;
            return;
        }

        int a = (i + i_)/2;
        int b = (j + j_)/2;
        
        helper(ans, i, a, j, b ,num);
        
        helper(ans, a+1, i_, j, b, num);
            
        helper(ans, a+1, i_, b+1 , j_, num);
            
        helper(ans,i, a, b+1, j_, num);
    }
    vector<vector<int>> specialGrid(int N) {
        int n = pow(2,N);
        vector<vector<int>> ans(n,vector<int>(n));
        int num = pow(2,2*N) - 1;
        helper(ans,0,n-1,0,n-1,num);
        return ans;
    }
};