class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> v;
        int m = rolls.size();
        int sum = 0;
        for(int r : rolls) sum += r;
        int value = mean * (m + n) - sum;
        if(value > 6 * n || mean > 6 || value < n) return {};
        else
        {
            int x = value / n;
            int y = value % n;
            for(int i = 0; i < n; i++) v.emplace_back(x);
            while(y > 0) 
            {
                v[y] += 1; 
                y--;
            }    
        }
        return v;
    }
};