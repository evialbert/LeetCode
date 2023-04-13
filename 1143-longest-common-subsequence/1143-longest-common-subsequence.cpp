class Solution {
public:
    string s1, s2;
    vector<vector<int>> dp; //cache of program
    int util(int i, int j){
        if(i>=s1.size() || j>=s2.size())return 0; //if any index goes out of bound then we should return

        if(dp[i][j]!= -1)return dp[i][j]; //if cache cell already filled then is there any need to calculate same task again.
        if(s1[i]==s2[j]){//matching
            return dp[i][j]= util(i+1, j+1)+1;//adding 1 to increase count and filling it in the brain
        }else{//if chars not matching we have two options either increase index of s1 or s2 and return the one who gives max for us.
            return dp[i][j]= max({util(i, j+1), util(i+1, j)});//brain fill.
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        s1= text1, s2= text2;
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));//filling our cache cells as -1.
        return util(0, 0);
    }
};