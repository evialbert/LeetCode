class Solution {
public: 
     int solve(int n){
         int sum =0;
         while(n%2==0){
             sum+=2;
             n = n/2;
         }
         for(int i=3;i<=sqrt(n);i++){
             while(n%i==0){
                 sum+=i;
                 n=n/i;
             }
         }
         if(n>2){
             sum+=n;
         }
         return sum;
     }

    int smallestValue(int n) {
        int ans = INT_MAX;
        while(ans!=solve(n)){
            ans = solve(n);
            n = ans;        }
            return ans;

    }
};