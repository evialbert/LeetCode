class Solution {
public:
   double average(vector<int>& salary) {
        int sm = salary[0], lg = sm, sum = 0;
        for (int sal : salary) {
            sm = min(sm, sal);
            lg = max(lg, sal);
            sum += sal;
        }
        return (double) (sum - sm - lg) / (salary.size() - 2);
    }
};