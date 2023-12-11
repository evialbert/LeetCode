class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;

        set<int> s;

        for(auto ele:nums){
            if(s.find(ele)!=s.end()) { ans.push_back(ele);  }
            s.insert(ele);
        }

        int n=nums.size();
   
   for(int i=1;i<=n;i++) 
   if(s.find(i)==s.end()) { ans.push_back(i);break;}

        return ans;
    }
};