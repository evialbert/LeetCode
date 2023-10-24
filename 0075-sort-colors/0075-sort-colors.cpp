class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0;
        int mid = 0 ;
        int right = n-1 ;
        
        while( mid <= right)
        {
		    // To store all the 0's at the beginning
            if( nums[mid] == 0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
			// To store 2's at the last
            else if( nums[mid] == 2){
                swap(nums[mid],nums[right]);
                right--;
            }
			//To store 1's at the middle
            else mid++;
        }
    }
};