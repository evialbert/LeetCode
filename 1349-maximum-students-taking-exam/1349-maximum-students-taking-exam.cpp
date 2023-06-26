class Solution {
private:
    //checks whether cheating is possible
    bool cheat(int prev_mask,int curr_mask){
        //whether the student can cheat from their own row
        if(curr_mask&(curr_mask>>1) or (curr_mask&(curr_mask<<1))){
            return true;
        } else if(curr_mask&(prev_mask>>1) or curr_mask&(prev_mask<<1)){
            //whether the students can cheat from the row in front of them
            return true;
        } else {
            return false;
        }
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        int rows=seats.size(),cols=seats[0].size();
        //stores the configuration of chairs
        //0->broken chair
        //1->good condition
        vector<int>validpos(rows,0);
        for(int i=0;i<seats.size();i++){
            for(int j=0;j<seats[i].size();j++){
                if(seats[i][j]=='.'){
                    validpos[i]^=(1<<j);
                }
            }
        }
		//stores the row and current row seating as state variables
        vector<vector<int>>dp(rows,vector<int>(1<<cols,-1));
        for(int i=0;i<rows;i++){
            //enumerating all possible combination of seating plans for the current row
            for(int curr_mask=0;curr_mask<(1<<cols);curr_mask++){
                //the current seating plan should not place a student on a broken chair, meaning 
                //the current seating plan should only place a student(1) where the chair is in good condition
                if((curr_mask|validpos[i])==validpos[i]){
				//count the number of 1s in the binary representation of a number
                    int cnt=__builtin_popcount(curr_mask);
                    if(i==0){
                        if(!cheat(0,curr_mask)){
                            dp[i][curr_mask]=cnt;
                        }
                    } else {
                        //enumerating all possible seating arrangements for the previous row
                        for(int prev_mask=0;prev_mask<(1<<cols);prev_mask++){
                            if((prev_mask|validpos[i-1])==validpos[i-1]){
                                if(dp[i-1][prev_mask]!=-1 and !cheat(prev_mask,curr_mask)){
                                    dp[i][curr_mask]=max(dp[i][curr_mask],dp[i-1][prev_mask]+cnt);
                                }
                            }
                        }
                    }
                }
            }
        }
        return *max_element(dp[rows-1].begin(),dp[rows-1].end());
    }
};