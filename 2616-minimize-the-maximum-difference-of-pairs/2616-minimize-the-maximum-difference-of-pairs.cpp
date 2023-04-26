class Solution {
public:
    bool checker(int maxi,vector<int> &nums,int p){
        int cnt=0,diff=0,i=0,n=nums.size();
        while(i<n-1){
            diff = nums[i+1] - nums[i];
            if(diff <= maxi){
                cnt++;
                i+=2;
            }
            else
               i++; 
        }
        return cnt>=p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int ll=0,ul=1e9,mid=0,ans;
        sort(nums.begin(),nums.end());
        while(ll<=ul){
            mid = (ll + ul) >> 1;
            if(checker(mid,nums,p)){
                ul = mid - 1;
                ans = mid;
            }
            else
                ll = mid + 1;
        }
        return ans;
        
    }
};