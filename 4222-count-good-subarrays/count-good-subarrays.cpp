class Solution {
public:


    long long countGoodSubarrays(vector<int>& nums) 
    {
        int n = nums.size();

        long long ans = 0;

        stack<int> my_stack;

        vector<int> next_non_xor(n, n);
        vector<int> prev_non_xor(n, -1);

        // Searching for an index of the next element whose bitwise OR product with nums[i] is not equal to nums[i]. If we encounter an element equal to nums[i] we stop there as well
        for(int i = 0 ; i < n ; i++)
        {
            while( !my_stack.empty() &&  (nums[my_stack.top()] != (nums[i] | nums[my_stack.top()] ) ||  nums[my_stack.top()] == nums[i]  )  )
            {
                next_non_xor[my_stack.top()] = i;
                my_stack.pop();

            }
            my_stack.push(i);
        }


        my_stack = {};

        // Searching for an index of the previous element whose bitwise OR product with nums[i] is not equal to nums[i]
        for(int i = n-1 ; i >= 0 ; i--)
        {
            while( !my_stack.empty() &&  nums[my_stack.top()] != (nums[i] | nums[my_stack.top()] )    )
            {
                prev_non_xor[my_stack.top()] = i;
                my_stack.pop();

            }
            my_stack.push(i);
        }

        // Finally, calculate the number of arrays
        for(int i = 0 ; i  < n ; i++)
        {
            ans += long(next_non_xor[i] - i) * long(i - prev_non_xor[i]);
        }


        
        return ans;
    }




    
};