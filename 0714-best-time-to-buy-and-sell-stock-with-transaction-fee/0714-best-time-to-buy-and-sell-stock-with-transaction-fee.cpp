class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s = 0, b = INT_MIN;
        for(auto x: prices){
            b = max(b,s-x);
            s = max(s,b+x-fee);
        }

        return s;
    }
};