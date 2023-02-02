class Solution {
public:
    int rev(int n){
        int res=0;
        while(n){
            res=res*10+n%10;
            n=n/10;
        }
        return res;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
		unordered_set<int> s;
        for(auto a:nums){
            s.insert(a);
            s.insert(rev(a));
        }
        return s.size();
    }
};