class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int i=0;
        reverse(num.begin(),num.end());
        while (true) {
            if (num[i]+k%10+carry<10) {
                num[i]+=k%10+carry;
                carry=0;
            }
            else {
                num[i]+=k%10+carry-10;
                carry=1;
            }
            i++;
            k/=10;
            if (i==num.size()) break;
        }
        int x=carry+k;
        while(x) {
            num.push_back(x%10);
            x/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};