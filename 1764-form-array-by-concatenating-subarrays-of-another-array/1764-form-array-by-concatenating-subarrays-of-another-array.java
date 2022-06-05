class Solution {
public boolean canChoose(int[][] groups, int[] nums) 
{
    int r = 0, n = groups.length, i = 0, k = 0;
    while(i < nums.length && r < n)
    {
        int prev = i;
        k = 0; 
        while(k < groups[r].length && i < nums.length && groups[r][k] == nums[i])
        {
            i++;
            k++;
        }
        
        if(k == groups[r].length)
        {
            r++;
        }
        else
        {
            i = prev+1;
        }
    }
    
    return r == n && k == groups[n-1].length;
}
}