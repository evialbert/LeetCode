class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int answer=0;
        stack<pair<int,int>> st;
        st.push({nums[nums.size()-1],0});
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            int count=0;
            while(!st.empty() && st.top().first<nums[i]) //if current element is greater  then the top of the stack(st.top().first) keep removing the top() element and simultaneously keep updating count
            {
                count=max(st.top().second,count+1);
                st.pop();
            }
            answer=max(answer,count);
            st.push({nums[i],count}); // push the new element in the stack
        }
        return answer;
    }
};