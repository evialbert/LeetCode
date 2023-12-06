class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        list<int> l = list<int>(arr.begin(), arr.end());
        int sum = 0;
        while (l.size() > 1)
        {
            list<int>::iterator it_min = l.begin();
            int min_val = numeric_limits<int>::max();
            for (auto it = l.begin(); it != l.end(); it++)
            {
                if (*it < min_val)
                {
                    it_min = it;
                    min_val = *it;
                }
            }
            
            auto it_smaller = l.end();
            if (it_min == l.begin())
            {
                it_smaller = next(it_min);
            }
            else if (it_min == prev(l.end()))
            {
                it_smaller = prev(it_min);
            }
            else
            {
                if (*prev(it_min) < *next(it_min))
                {
                    it_smaller = prev(it_min);
                }
                else
                {
                    it_smaller = next(it_min);
                }
            }

            sum += *it_min * *it_smaller;
            l.erase(it_min);
        }

        return sum;
    }
};