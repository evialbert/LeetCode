class Solution {
    public int maxValue(int n, int index, int maxSum) {
       int l = index; // Number of elements in left part
        int r = n-index-1; // Number of elements in right part
        
        // range for nums[index]
        long lo = 1;   
        long high = maxSum;
        
        long sum =0;
        
        // final answer is stored in res
        long res =0;
        
        
        while(lo <= high)
        {
            long mid = lo + (high-lo)/2;
            long ls =0; // Left Part sum
            long rs = 0; // Right Part Sum
            sum = mid;
            
            long m = mid-1;  // used in finding left sum and right sum
            
            if(r > 0)
            {
                if(r<=m)   
                {   /*
                    When right part is filled with decreasing order natural numbers
                    then use this formula
                    */
                    rs = m*(m+1)/2 - (m-r)*(m-r+1)/2;
                }else
                    /*
                    When right part is filled with 1's then use this formula
                    */
                    rs = m*(m+1)/2 + 1*(r-m);
            }
            if(l>0)
            {
            if(l<=m)
                
                /*
                9+8+7+6 = (1+2+3+4+5+.......+8+9) - (1+2+3+4+5)
                */
                ls = m*(m+1)/2 - (m-l)*(m-l+1)/2;
            else
                     
                ls = m*(m+1)/2 + 1*(l-m);
            }
            // sum = left part + mid element + right part
            sum = sum +ls +rs;
            
            if(sum <= maxSum)
            {   res = Math.max(res,mid);  // Storing the maximum nums[index] 
                //System.out.print(res);
                lo = mid+1;
            }else{
                high = mid-1;
            }
            
            
        }
        
        return (int)res;
        
        
        
    }
}