class Solution {
public:
    int maximum69Number (int num) {
        int pos = -1;
        int i = num;
        int j=1;

        while(i>0)
        {
            if(i%10==6) pos = j;

            j*=10;
            i/=10;
        }

        if(pos == -1) return num;
        else return num+(3*pos);
    }
};