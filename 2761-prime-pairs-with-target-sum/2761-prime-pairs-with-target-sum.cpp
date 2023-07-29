class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;

        for(int i=2; i*i<=n; i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> v;
        for(int x=2; x<=n/2; x++){
            int y = n-x;

            if(isPrime(x) && isPrime(y)){
                vector<int> pair = {x,y};
                v.push_back(pair);
            }
        }
        return v;
    }
};
