class Solution {
public:
    long long merge(int low,int mid,int high,vector<int>& nums,int& diff){
        long long count=0;
        int l=low,r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]+diff){
                count+=(high-r+1);
                l++;
            }else{
                r++;
            }
        }
        sort(nums.begin()+low,nums.begin()+high+1);
        return count;
    }

    long long mergeSort(int low,int high,vector<int>& nums,int& diff){
        if(low>=high) return 0;
        long long pairs=0;
        int mid = (low+high)/2;
        pairs+=mergeSort(low,mid,nums,diff);
        pairs+=mergeSort(mid+1,high,nums,diff);
        pairs+=merge(low,mid,high,nums,diff);
        return pairs;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for(int i=0;i<n;++i){
            nums[i] = nums1[i]-nums2[i];
        }
        return mergeSort(0,n-1,nums,diff);
    }
};