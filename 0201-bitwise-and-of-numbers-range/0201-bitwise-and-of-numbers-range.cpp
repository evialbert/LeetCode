class Solution {
public:
    int binaryToDecimal(bitset<32> num)
    {
        
        int dec_value = 0;
        bitset<1> comp(1);
        long long base = 1;

        int len = num.size();
        for (int i = 0; i < 32; i++) {
            if (num[i] == comp[0])
                dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> bset1(left);
        bitset<32> bset2(right);
        bitset<32> ans;
        int i = 31;
        while(i >= 0 && bset1[i] == bset2[i]){
            ans[i] = bset1[i];
            i--;
        }
        int a = binaryToDecimal(ans);
        
        return a;
    }
};