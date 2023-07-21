class Solution {
public:
	int minOperations(vector<int>& nums) {
		int n = nums.size();
		
		int ans=INT_MAX;
		sort(nums.begin(),nums.end());
		nums.erase(unique(nums.begin(),nums.end()),nums.end());
		int m = nums.size();
		
		int j=0;
		for(int i=0;i<m;i++){
			while(j<m && nums[j] < nums[i]+n){
				j++;
			}
			ans = min(ans,n-j+i);
		}
		return ans;
	}
};