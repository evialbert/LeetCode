class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++)
        arr.push_back({nums[i],i});
        sort(arr.begin(),arr.end());
        int group=0;
        nums[arr[0].second]=group;
        vector<int>group_start;
        group_start.push_back(0);
        for(int i=1;i<n;i++)
        {
            if(arr[i].first-arr[i-1].first>limit)
            {
                group++;
                group_start.push_back(i);
            }
            nums[arr[i].second]=group;
        }
        for(int i=0;i<n;i++)
        {
            int g=nums[i];
            int index=group_start[g]++;
            nums[i]=arr[index].first;
        }
        return nums;

        
    }
};