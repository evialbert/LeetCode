class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        for(int i=0;i<brackets.size();i++)
        {
            if(i==0)
            {
                double a = (double)min(income,brackets[i][0]);
                double b = (brackets[i][1])/100.0;
                income-=a;
                ans+=(a*b);
            }
            else
            {
                int x = brackets[i][0]-brackets[i-1][0];
                double a =(double) min(income,x);
                double b = (brackets[i][1])/100.0;
                income-=a;
                ans+=(a*b);
            }
        }
        return ans;
    }
};