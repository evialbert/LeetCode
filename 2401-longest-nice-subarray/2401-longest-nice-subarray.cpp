class Solution {
public:
int longestNiceSubarray(vector<int>& nums) 
    {
        int ans = 1;
        int currlen = 1;
        int i = 0;
        while(i < nums.size()-1)
        {
            if((nums[i] & nums[i+1]) == 0)
            {
              currlen++;
              if(currlen > 2)
              {
                  int check = 1;
                  int checked_len = 2;
                  while(checked_len != currlen)
                  {
                      if((nums[i-check] & nums[i+1]) == 0)
                      {
                          checked_len++;
                          check++;
                      }
                      else
                          break;
                  }
                  if(checked_len != currlen)
                      currlen = checked_len;    
              }
              ans = max(ans,currlen);  
              i++;  
            }
            else
            {
               currlen = 1;    
               i++;
            }     
        }
      return ans;  
    }
};