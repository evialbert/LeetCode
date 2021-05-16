class Solution {
    public int numSubarrayProductLessThanK(int[] arr, int k) {
        int n=arr.length;
        int count=0;
		if(k<=1)
			return 0;
		int prod=1;
		int start=0;
		int end=0;
		while(end<n)
		{
			prod=prod*arr[end];//calculate the product
			while(prod >= k)//if the product is greater than or equal to k,then change its boundary
			{
				prod=prod/arr[start];
				start++;
			}
			count=count+end-start+1;
			end++;
		}
		return count;
    }
}