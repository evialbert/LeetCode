class Solution {
public:
    //Time complexity: O(n)
    //Space complexity: O(1)
    int reductionOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> v(*max_element(nums.begin(),nums.end())+1,0);
        for(int i=0;i<nums.size();i++)
        v[nums[i]]++;
        int k=1,s=0;
        for(int i=*min_element(nums.begin(),nums.end())+1;i<v.size();i++){
            if(v[i]!=0){
                s+=v[i]*k;
                k++;
            }
        }
        return s;
    }
};