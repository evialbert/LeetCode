class Solution {
public:
	int arraySign(vector<int>& nums) {
		int nc=0,zc=0;
		for(int i=0;i<nums.size();i++){
			if(nums[i]<0)nc++;
			else if(nums[i]==0)zc++;
		}
		if(zc!=0)return 0;
		else if(nc%2!=0)return -1;
		return 1;
	}
};