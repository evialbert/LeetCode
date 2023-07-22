class Solution {
public:
    long long countSmallerProducts(vector<int>& nums1, vector<int>& nums2, long long product){
        long long count=0;
        for(int num:nums1){
            if(num>=0){
                int l=0,h=nums2.size()-1,temp=-1;
                while(l<=h){
                    int mid=l+(h-l)/2;
                    if((long long)num*nums2[mid] <= product){
                        temp=mid;
                        l=mid+1;
                    }else h=mid-1;
                }
                count+=temp+1;
            }else{
                int l=0,h=nums2.size()-1,temp=nums2.size();
                while(l<=h){
                    int mid=l+(h-l)/2;
                    if((long long)num*nums2[mid] <= product){
                        temp=mid;
                        h=mid-1;
                    }else l=mid+1;
                }
                count+=(nums2.size()-temp);
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long s=-1e10,e=1e10,ans=0;
        
        
        while(s<=e){
            long long mid = (s+e)/2;
            if(countSmallerProducts(nums1,nums2,mid)>=k){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        
        return ans;
    }
};