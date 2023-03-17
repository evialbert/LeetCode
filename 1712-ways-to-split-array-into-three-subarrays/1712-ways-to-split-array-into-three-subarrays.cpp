class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        long long mod=1000000007;
        if(n<3){
            return 0;
        }
        
        vector<long long> prefixSum;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        
        long long cnt=0;
        for(int i=0;i<(n-2);i++){
            long long curr_sum=prefixSum[i];
            int l=i+1,r=n-2;
            while(l<=r){
                int mid=(l+r)/2;
                long long left_sum=prefixSum[mid]-prefixSum[i];
                long long right_sum=prefixSum[n-1]-prefixSum[mid];
                if(left_sum>right_sum){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            

            int right_idx=r;  
            l=i+1,r=n-2;
            while(l<=r){
                int mid=(l+r)/2;
                long long val=prefixSum[mid]-prefixSum[i];
                if(val<curr_sum){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            } 
            int left_idx=l;       

        
            if(left_idx>right_idx){
                continue;
            }else{
                cnt+=(right_idx-left_idx+1);
            }
            
            
            
        }
        
        return cnt%mod;
        
        
        
    }
};