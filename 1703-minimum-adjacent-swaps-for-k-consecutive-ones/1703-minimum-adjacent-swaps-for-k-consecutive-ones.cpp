class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int>Ones;
        // Take All one's indexies
        for(int i=0;i<nums.size();i++)
            if(nums[i])
                Ones.push_back(i);
        
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int left_part;
        int right_part;
        int left;
        int right;
        
        
        // Caculate For No of Swaps
        if(k%2)
        {   left=k/2;
            right=k/2;
            left_part=((k/2)*(k/2+1))/2;
            right_part=left_part;
        }
        else
        {
            int a=k/2;
            left=a-1;
            right=a;
            left_part=((a-1)*(a))/2;
            right_part=((a)*(a+1))/2;
        }
        
        
        int median=(k-1)/2;
        int sum=0;
        int prev_median=(k-1)/2;
        int shift_value;
        
        
        // create a window of size 'k'
        while(j-i+1<k)
        {
            // Do Pre-Calculation
            sum+=abs(Ones[j]-Ones[i+median]);
            
            j++;   
        }
        
        
        // Apply Fix size sliding window with median concept
        while(j<Ones.size())
        {
            shift_value=abs(Ones[median+i]-Ones[prev_median]);
            shift_value=shift_value*left-(shift_value*(right));
            
               // Do Pre-Calculation
            sum+=abs(Ones[j]-Ones[i+median])+shift_value;
            
            // Store result
            ans=min(ans,sum-left_part-right_part);
            
            // Remove Calculation for i
            sum-=abs(Ones[i]-Ones[i+median]);
            prev_median=i+median;
            
            // Slide the window with maintaining the size of window
            i++;
            j++;
        }
        
        
        return ans;
    }
};
