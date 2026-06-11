class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> moves(n);
        moves[0]=1;
        moves[n-1]=-1;
        for(int i=1;i<n-1;i++) {
            if(abs(nums[i-1]-nums[i])<abs(nums[i+1]-nums[i])) moves[i]=-1;
            if(abs(nums[i-1]-nums[i])>abs(nums[i+1]-nums[i])) moves[i]=1;
            if(abs(nums[i-1]-nums[i])==abs(nums[i+1]-nums[i])) moves[i]=-1;
        }

        vector<int> right(n),left(n);
        right[0]=0;
        for(int i=1;i<n;i++) {
            right[i]=right[i-1]+(moves[i-1]>0?moves[i-1]:abs(nums[i]-nums[i-1]));
        }

        left[n-1]=0;
        for(int i=n-2;i>=0;i--) {
            left[i]=left[i+1]+(moves[i+1]<0?abs(moves[i+1]):abs(nums[i]-nums[i+1]));
        }

        vector<int> res;
        for(auto query : queries) {
            if(query[0]<query[1]) {
                res.push_back(right[query[1]]-right[query[0]]);
            } else {
                res.push_back(left[query[1]]-left[query[0]]);
            }
        }

        return res;
    }
};