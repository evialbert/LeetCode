class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        sort(capacity.begin(),capacity.end(),greater<int>());
        
        int sum=0;
        sum = accumulate(apple.begin(),apple.end(),0);
        
        int ans=0;
        while(sum>0)
        {
            sum-=capacity[ans];
            ans++;
        }
        return ans;
    }
};