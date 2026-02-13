class Solution {
    bool isPrime(int num){
        if(num == 1) return false;
        for(int i = 2; i * i <= num; i++){
            if((num % i) == 0) return false;
        }
        return true;
    }
public:
    bool completePrime(int num) {
        string S = to_string(num);
        for(int i = 0; i < S.length(); i++){
            string newS = S.substr(0,i + 1);
            int num1 = stoi(newS);
            if(!isPrime(num1)) return false;
        }
        string newS2 = "";
        for(int i = S.size() - 1; i >= 0; i--){
             newS2 = S[i] + newS2;
            int num2 = stoi(newS2);
            if(!isPrime(num2)) return false;
        }
      return true;
    }
};