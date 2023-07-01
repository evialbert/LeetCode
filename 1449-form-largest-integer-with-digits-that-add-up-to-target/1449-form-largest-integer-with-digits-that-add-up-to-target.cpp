class Solution {
public:
    string maxString(string a, string b){
        if(a.size()>b.size())
            return a;
        else if(a.size()<b.size())
            return b;
        else{
            if(a>b)
                return a;
            else
                return b;
        }
        return "";
    }
    
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> dp(10, vector<string>(target+1, "0")); // 0 means no path possible
        
        for(int i=0; i<10; i++)
            dp[i][0]=""; // means path possible when cost is 0.
            
        for(int i=1; i<10; i++){
            for(int j=1; j<=target; j++){
                dp[i][j]=dp[i-1][j];
                if(cost[i-1]<=j){
                    string partial;
                    if(dp[i][j-cost[i-1]]!="0"){ // if not 0 i.e. path possible after choosing this element
                        partial=to_string(i)+dp[i][j-cost[i-1]];
                        dp[i][j]=maxString(dp[i][j], partial); // Custom max string as cannot compare string as it only compares first character.
                    }
                }
            }
        }
        
        return dp[9][target];
    }
};