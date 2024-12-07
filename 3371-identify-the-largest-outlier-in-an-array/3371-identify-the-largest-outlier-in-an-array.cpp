class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long tsum = 0;
        unordered_map<int,int> freq;
        for(auto it: nums){
            tsum += it;
            freq[it]++;
        }

        int ans = INT_MIN;
        for(auto num: nums){
            freq[num]--;
            long reqdoublesum = tsum-num;
            if(reqdoublesum %2 ==0){
                int reqsum = reqdoublesum/2;
                if(freq[reqsum]>0){
                    ans = max(ans,num);
                }
            }
            freq[num]++;
        }
        return ans;
    }
};