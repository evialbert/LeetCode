class Solution {
public:
	int help(vector<int>&nums1,vector<int>&nums2){
		int mx = 0;
		for(int i=0,kad = 0;i<size(nums1);i++){
			kad = max(kad+nums2[i]-nums1[i],nums2[i]-nums1[i]);
			mx = max(kad,mx);
		}
		return accumulate(begin(nums1),end(nums1),0) + mx;
	}

	int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
		return max(help(nums1,nums2),help(nums2,nums1));
	}
};