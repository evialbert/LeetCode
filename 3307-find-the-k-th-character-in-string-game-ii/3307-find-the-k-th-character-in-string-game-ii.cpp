class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        long long int  increment = 1;
        long long int count =0;
        while(increment<k){
            increment*=2;
            count++;
        }
        increment/=2;
        count--;
        char character = kthCharacter(k-increment , operations);
        if(character=='z'){
            if(operations[count]==1) return 'a';
            else return 'z';
        }
        else {
            return character + operations[count];
        }
    }
};