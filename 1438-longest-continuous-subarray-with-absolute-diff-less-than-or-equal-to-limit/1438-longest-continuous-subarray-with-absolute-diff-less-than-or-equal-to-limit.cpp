class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        int res = 0;
		deque<pair<int,int>> minQ;
		deque<pair<int,int>> maxQ;
		int j=0;

        for(int i=0;i<nums.size();i++)
        {
            //Calc
            int next = nums[i];
            //MaxQ
            while(!maxQ.empty() && maxQ.back().first<next){
                maxQ.pop_back();
            }
            maxQ.emplace_back(next,i);

            //MinQ
            while(!minQ.empty() && minQ.back().first>next){
                minQ.pop_back();
            }
            minQ.emplace_back(next,i);


            //Answer Generation
            if(maxQ.front().first - minQ.front().first <=k)
            {
                res=max(res,i-j+1);
            }
            else
            {
                j++;

                while(!minQ.empty() && minQ.front().second<j) minQ.pop_front();
                while(!maxQ.empty() && maxQ.front().second<j) maxQ.pop_front();
            }
        }

        return res;
    }
};