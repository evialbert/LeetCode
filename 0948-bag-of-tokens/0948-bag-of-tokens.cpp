class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0;
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int l=0,r=n-1,score=0;
        while(l<=r and power>=tokens[l]){
            while(l<=r and power>=tokens[l]){
                score+=1;
                power-=tokens[l];
                l+=1;
            }
            ans=max(ans,score);
            while(r>=l and score>0 and power<tokens[l]){
                score-=1;
                power+=tokens[r];
                r-=1;
            }
        }
        return ans;
    }
};