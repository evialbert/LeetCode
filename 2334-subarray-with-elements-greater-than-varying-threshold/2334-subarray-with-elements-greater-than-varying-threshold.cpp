class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int N = nums.size();
        vector<int> left(N,-1);
        stack<int> St;
        for(int i=N-1;i>=0;i--){
            while(!St.empty() && nums[i] < nums[St.top()]){
                int ele = St.top();
                St.pop();
                
                left[ele] = i;
            }
            St.push(i);
        }
      
        while(!St.empty()) St.pop();
        
        vector<int> right(N,N);
        for(int i=0;i<N;i++){
            while(!St.empty() && nums[i] < nums[St.top()]){
                int ele = St.top();
                St.pop();
                
                right[ele] = i;
            }
            St.push(i);
        }
    
        for(int i=0;i<N;i++){
            int len = right[i]-left[i]-1;
            int ele = threshold/len;
            
            if(nums[i] > ele) return len;
        }
        return -1;
    }
};