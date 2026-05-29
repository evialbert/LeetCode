bitset<128> hasC;
string digAlpha="0123456789abcdefghijklmnopqrstuvwxyz";

class Solution {
public:
    static constexpr char mirror(char c){
        if (c>='a') return 'a'+'z'-c;
        return '0'+'9'-c;
    }

    static int mirrorFrequency(string& s) {
        hasC.reset();
        int freq[128]={0};
        for(char c : s) 
            freq[c]++;

        int sum=0;
        for(char c: digAlpha){
            // already processed 
            if (hasC[c]) continue; 

            int fc=freq[c];
            char m=mirror(c); 
            hasC[m]=1;  //skip the mirror m

            int fm=freq[m];
            sum+=abs(fc-fm);
        }
        return sum;
    }
};