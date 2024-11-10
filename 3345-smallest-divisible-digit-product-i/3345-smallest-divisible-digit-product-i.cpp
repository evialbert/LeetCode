class Solution {
public:

    int product(int num){
        int pr = 1;
        while(num > 0){
            pr *= (num%10);
            num /= 10;
        }
        return pr;
    }

    int smallestNumber(int n, int t) {
        int num = n;
        while(1){
            if(product(num) % t == 0) return num;
            num = num+1;
        }
        return -1;
    }
};