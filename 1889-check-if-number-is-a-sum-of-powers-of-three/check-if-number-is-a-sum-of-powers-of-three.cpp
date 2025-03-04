class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            if(n%3==0) n/=3;
            else{
                if((n-1)%3==0) n--;
                else return false;
            }
        }
        return true;
    }
};