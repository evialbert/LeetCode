class Solution {
public:
    long long subarrayCnt(vector<int>& nums, int x){
        long long cnt=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        int l=0, r=-1;
        while(r<n-1){
            if(mp.find(nums[r+1])!=mp.end() || mp.size()<x){
                r++;
                mp[nums[r]]++;
                cnt += r-l+1;
            }
            else{
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return cnt;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        int n=nums.size();
        int l=1, h=n, ans=n;
        long long k = (1LL*n*(n+1)/2+1)/2;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(subarrayCnt(nums,mid)>=k){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};