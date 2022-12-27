class Solution {
private:
    void generate(vector<string>&ans, string p, int n, int m){
        if(n ==0 and m ==0){
            ans.push_back(p);
            return;
        }
        
        if(n > 0)
            generate(ans, p + '(', n-1, m+1);// n-1 ( will be add and ) this will be ++
        if(m > 0)
            generate(ans, p + ')', n, m-1); // ) once done reduce the count of )
        
    }
public:
    vector<string> generateParenthesis(int n) {
        //all pair => backtrack we can have the 
        /*
        1 => () | 2 => (()) , ()()
        */
        
        vector<string> ans;
        string p = "";
        generate(ans,p,n,0);
        return ans;
    }
};