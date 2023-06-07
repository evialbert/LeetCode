class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        int count = 0;

        while(a || b || c)
        {
            int aa = a&1;
            int bb = b&1;
            int cc = c&1;

            if((aa | bb) != cc)
            {
                if(cc == 1)
                    count += 1;
                else
                {
                    count += (aa == 1) ? (1) : (0);
                    count += (bb == 1) ? (1) : (0);
                }
            }

            a /= 2;
            b /= 2;
            c /= 2;
        }

        return count;
    }
};