class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        // Sum of all element in vector        
        int sum = accumulate( nums.begin(), nums.end(),0);

        //sum all digit of every element
        int digit_sum = 0;
        for( int i = 0; i < nums.size(); ++i){

            int n = nums[i];
            
            while( n!=0 ){
                digit_sum += n % 10;
                n = n / 10;
            }
            
        }
  
        //return absolute differnce between digit_sum and elment sum
           return abs( sum - digit_sum );
    }
};