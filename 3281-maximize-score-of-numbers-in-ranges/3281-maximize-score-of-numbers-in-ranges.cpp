class Solution {
public: 
    bool ispossible(long long mid,vector<int>& start,int d){
        int a = start[0];
        for(int i = 1;i < start.size();i++){
            if(a + mid < start[i])a = start[i];
            else if(a + mid >= start[i] && a + mid <= start[i] + d)a = a + mid;
            else return false;
        }
        return true;

    }
    int maxPossibleScore(vector<int>& nums, int d) {
        sort(nums.begin(),nums.end());

        long long start = 0;
        long long end = nums[nums.size() - 1] + d - nums[0];
        
        long long answer = 0;
        long long mid = start + (end - start)/2;
        while(start <= end){
            if(ispossible(mid,nums,d)){
                answer = max(answer,mid);
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return answer;
        
    }
};