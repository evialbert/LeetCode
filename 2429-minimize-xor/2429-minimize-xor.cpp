class Solution {
public:
    int minimizeXor(int num1, int num2) 
    {
        int no_bit = 0,n1 = num1,n2 = num2;
        while (n2 != 0)
        {
            if (n2 & 1)
                no_bit++;
            n2 = n2 >> 1;
        }
        vector<int> vp;
        int a = 1;
        while(n1 != 0)
        {
            if (n1 & 1){
                vp.push_back(a);
            }
            a = (a << 1);
            n1 = n1 >> 1;
        }
        int ans = 0;
        for (int i = vp.size()-1; i >= 0 && no_bit > 0; i--){
            ans += vp[i];
            no_bit--;
        }
        a = 1;
        int i = 0;
        while(no_bit > 0)
        {
            if (i < vp.size() && vp[i] == a)
            {
                i++;
                a = a << 1;
            }
            else
            {
                ans += a; 
                a = a << 1;
                no_bit--;
            }
        }
        //cout << ans;
        return ans;
    }
};