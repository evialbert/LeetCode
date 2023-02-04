class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> s1;  // For storing new elements
        stack<int> s2;  // For storings elements who need 2nd grater
        stack<int> temp; // For keeping the order intact while moving from s1 to s2
        vector<int> res(n, -1); 
        for(int i=0; i<n; i++){
            // Check if current element is grater than top, then push to answer
            while(!s2.empty() && nums[s2.top()] < nums[i]){
                res[s2.top()] = nums[i];
                s2.pop();
            }

            // check if we found first grater element in current
            while(!s1.empty() && nums[s1.top()] < nums[i]){
                temp.push(s1.top());
                s1.pop();
            }

            // keep the sequence intact while storing into s1
            while(!temp.empty()){
                s2.push(temp.top());
                temp.pop();
            }

            // Need to find first grater element
            s1.push(i);
        }
        return res;
    }
};