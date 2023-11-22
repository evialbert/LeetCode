class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        priority_queue<
        std::pair<int, std::pair<int, int>>,
        std::vector<std::pair<int, std::pair<int, int>>>,
        std::greater<std::pair<int, std::pair<int, int>>>
        > pq;
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            for(j=0;j<nums[i].size();j++)
            {
                
                pq.push({i+j,{j,nums[i][j]}});
            }
        }
        vector<int>ans;
        while(pq.size())
        {
            int p=pq.top().second.second;
            ans.push_back(p);
            pq.pop();
        }
        return ans;
    }
};