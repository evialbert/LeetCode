class Solution {
	public int[] sortEvenOdd(int[] nums) {

		// sorting even 
		for(int i=0; i<nums.length-2; i+=2){
			for(int j=i+2; j<nums.length; j+=2){
				if(nums[i] > nums[j]){
					int temp=nums[i];
					nums[i]=nums[j];
					nums[j] = temp;
				}
			}
		}

		// sorting odd
		int start = (nums.length-1) % 2 ==0?nums.length-2 : nums.length-1; 
		for(int i=start; i>0; i-=2){
			for(int j=i-2; j>=0; j-=2){
				if(nums[i] > nums[j]){
					int temp=nums[i];
					nums[i]=nums[j];
					nums[j] = temp;
			}
			}
		}

		return nums;
		}
}