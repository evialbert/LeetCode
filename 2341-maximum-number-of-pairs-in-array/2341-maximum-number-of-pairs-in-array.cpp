class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        stack<int>s;
        for(int i=0; i<nums.size(); i++){
            s.push(nums[i]);
        }
        int pair = 0;
        int alone = 0;
        while(!s.empty()){
            int a = s.top();
            s.pop();
            if(!s.empty() && s.top()==a){
                pair++;
                s.pop();
            }else{
                alone++;
            }
        }
        ans.push_back(pair);
        ans.push_back(alone);
        return ans;
    }
};