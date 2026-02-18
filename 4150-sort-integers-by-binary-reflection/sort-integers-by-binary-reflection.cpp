class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int>b){
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    }

    int find(int n){
        vector<int> temp;
        while(n > 0){
            int rem = n%2;
            temp.push_back(rem);
            n/=2;
        }
        int val = 0;
        int j=temp.size()-1;
        for(int i=0;i<temp.size();i++){
            val += pow(2,i)*temp[j];
            j--;
        }
        temp.clear();
        return val;
    }
    
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<int> revbin(nums.size());
        for(int i=0;i<n;i++){
            revbin[i] = find(nums[i]);
        }
        vector<pair<int, int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i], revbin[i]});
        }

        sort(temp.begin(), temp.end(), compare);

        vector<int> ans;
        for(auto ele: temp){
            ans.push_back(ele.first);
        }
        revbin.clear();
        temp.clear();
        return ans;
    }
};