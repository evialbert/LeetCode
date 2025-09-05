class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum=0,digitProd=1;
        int x=n;
        while(x!=0) {
            digitSum+=x%10;
            digitProd*=x%10;
            x/=10;
        }
        return (n%(digitSum+digitProd)==0);
    }
};