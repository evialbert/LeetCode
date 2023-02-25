class Solution {
public:
    int countDigits(int num) {
        int copy_of_num = num;
        int count = 0;
        while(num>0){
            int last_digit = num%10;
            if(copy_of_num%last_digit == 0)
                count = count + 1;
            num = num/10;
        }
        return count;
    }
};