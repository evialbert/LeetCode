class Solution {
public:
    int search(vector<int>& nums, int target) {
    //there exists atleast one strictly increasing subarray due to pivot element
    //using modified binary search 
        int n=nums.size();
        int s=0;
        int e=n-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(nums[mid] == target) return mid;
  //else if left subarray is str increasing then search only in the LEFT SUBARRAY          
            else if(nums[mid]>=nums[s]){
                if(target>=nums[s] && target <=nums[mid]){
                    
                    e =mid-1;//update the right pointer
                    
                }
                else
                    s=mid+1;//update the left pointer
            }
 //else search in the RIGHT SUBARRAY
            else{
                if(target>=nums[mid] && target<=nums[e]){
                    
                    s=mid+1;
                    
                }
                else
                    e=mid-1;
            }
            
        }
        
        return -1;//if it is not PRESENT
    }
};