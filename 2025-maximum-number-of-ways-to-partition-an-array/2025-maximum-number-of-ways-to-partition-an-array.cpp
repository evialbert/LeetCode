class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {

        vector<long long> pref(nums.size());
        unordered_map<long long, int> seg_diff; //total seg diff count record
        vector<int> count_per_position(nums.size(),0);
        
        for(int i=0;i<nums.size();++i){
            pref[i] = (i>0?pref[i-1]:0) + nums[i];
        }
        
        //compute diff of sums of right versus left partitions
        for(int pivot=1;pivot<nums.size();++pivot){       
            long long sum_left = pref[pivot-1];
            long long sum_righ = pref[nums.size()-1] - sum_left;
            seg_diff[sum_righ - sum_left]++; // extra amount right sum has compared to left sum
        }                

        
        //consider not changing number
        int ans = 0;
        {
            for(int pivot=1;pivot<nums.size();++pivot){
                long long sum_left = pref[pivot-1];
                long long sum_righ = pref[nums.size()-1] - sum_left;
                ans += (sum_left - sum_righ==0)? 1 : 0;
            }
        }
        //consider changing a number in the left partition
        {
            unordered_map<long long, int> seg_diff_seen;
            for(int i=0;i<nums.size()-1;++i){
                
                long long num_diff = k - nums[i]; //current delta
                
                //get number of segment_diffs with current position in left partition that has num_diff in value 
                count_per_position[i] = seg_diff[num_diff] - seg_diff_seen[num_diff];
                
                //segment difference
                long long sum_left = pref[i];
                long long sum_righ = pref[nums.size()-1] - sum_left;
                long long d = sum_righ - sum_left;
                seg_diff_seen[d]++;
            }
        }
        //consider changing a number in the right partition
        {
            unordered_map<long long, int> seg_diff_seen;
            for(int i=nums.size()-1;i>=1;--i){
                
                long long num_diff = k - nums[i]; //current delta
                
                //get number of segment_diffs with current position in right partition that has -num_diff in value 
                count_per_position[i] += seg_diff[-num_diff] - seg_diff_seen[-num_diff];
                
                //segment difference
                long long sum_left = pref[i-1];
                long long sum_righ = pref[nums.size()-1] - sum_left;
                long long d = sum_righ - sum_left;
                seg_diff_seen[d]++;
            }
        }
        
        for(auto i: count_per_position){
            ans = max(ans, i);
        }
        
        return ans;
    }
};