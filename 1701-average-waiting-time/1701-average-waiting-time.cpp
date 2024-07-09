class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int lct = 0;
        double wt = 0;
        for(int  i = 0; i < c.size(); i++){
            if(lct > c[i][0]){
                wt += lct + c[i][1]  - c[i][0] ;
                lct += c[i][1];
            } 
            else {
                wt += c[i][1] ;
                lct = c[i][1] + c[i][0];
            }
        }
        return wt/c.size();
    }
};