class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();

        int i = 0, j = n-1;

        if( n % 2 == 1 ) j = n-2;

        while ( i < n && j > 0){

            if( nums[i]%2 == 1 ){

                while( nums[j] % 2 != 0 && j > 0 ) j = j - 2;

                swap( nums[i], nums[j]);
            }

            i = i + 2;
        }

        return nums;
    }
};