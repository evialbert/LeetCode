class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {

        // Sort the vector to get the highest value elements in the end
        sort(nums.begin(), nums.end());

        // Hashing used for taking each element only once.
        unordered_map<int,int> mp;
        vector<int> res;

        // Start from the back so that we have the highest value elements
        for(int i = nums.size() - 1; i >=0 ; i--) {

            //If the element is not present in the map then only take it, else continue
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]]++;
                res.push_back(nums[i]);
                k--;

                // If we have taken k elements then break out off the loop.
                if(k == 0) break;
            }
        }

        return res;
    }
};