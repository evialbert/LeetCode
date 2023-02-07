class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        
        int i=0,j=n-1;
        
        set<double> st;
        
        sort(nums.begin(),nums.end());
            
        while(n > 0){
            double average = (nums[i]+nums[j])/2.0;
            st.insert(average);
            i++;
            j--;
            n--;
        }
        
        return st.size();
    }
};