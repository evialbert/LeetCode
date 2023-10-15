class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> nums,index;
        for(int i=0 ; i<groups.size() ; i++){
            if(nums.size()==0){
                nums.push_back(groups[i]);
                index.push_back(i);
            }
            if(groups[i]!=nums[nums.size()-1]){
                nums.push_back(groups[i]);
                index.push_back(i);
            }
        }
        vector<string> ans;
        for(int i=0 ; i<index.size() ; i++){
            ans.push_back(words[index[i]]);
        }
        return ans;
    }
};