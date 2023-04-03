class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        
        int n = nums.size();
        
        // declare an unordered set
        
        unordered_set<int> s;
        
        // push all the elements of nums into set
        
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        
        // start searching power of 2 into set
        
        int pow = 1;
        
        while(s.count(pow))
        {
            pow = pow * 2;
        }
        
        return pow;
    }
};