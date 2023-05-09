class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
    int o=0,t=0;
    
        for(int i=0;i<player1.size();i++){
            
            if(i>=1 and player1[i-1]>=10) o+=2*player1[i];  // just checking previous turn for 10 or greater
            else if(i>=2 and (player1[i-1]>=10 or player1[i-2]>=10)) o+=2*player1[i]; // checking previous 2 turn for a 10 or greater
            else o+=player1[i];   // else add that value
        }
     for(int i=0;i<player2.size();i++){
            
         if(i>=1 and player2[i-1]>=10) t+=2*player2[i];
           else if(i>=2 and (player2[i-1]>=10 or player2[i-2]>=10)) t+=2*player2[i];
            else t+=player2[i];
        }
    if(o>t) return 1;
    else if(t>o) return 2;
    else return 0;
    }
};