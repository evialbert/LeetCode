class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int temp = nums[i];
            vector<int> store;
            while(temp){
                int c = temp%10;
                store.push_back(c);
                temp = temp/10;
            }
            reverse(store.begin(),store.end());
            for(int i = 0; i<store.size(); i++){
                nums.push_back(store[i]);
            }
        }
        nums.erase(nums.begin(),nums.begin()+n);
        return nums;
    }
};