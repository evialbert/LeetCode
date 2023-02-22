class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid) {
        int curdays=1;
        int cursum=0;
        for(int i=0;i<weights.size();i++) {
            if(weights[i]>mid)
                return false;
            cursum+=weights[i];
            if(cursum>mid){
                curdays++;
                cursum=weights[i];
            }   
            if(curdays>days)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.size()<days) return -1;
        int max_wt=INT_MIN, sum=0, ans=-1;
        
        for(int i=0;i<weights.size();i++) {
            sum+=weights[i];
            max_wt=max(max_wt,weights[i]);
        }
        
        int start=max_wt;
        int end=sum;
        int mid;
        while(start<=end) {
            mid=start+(end-start)/2;
            if(isPossible(weights, days, mid)) {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        
        return ans;
    }
};