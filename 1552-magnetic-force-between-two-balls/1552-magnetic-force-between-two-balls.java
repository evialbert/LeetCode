class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int start = 0, end = position[position.length - 1] - position[0], ans = 0;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(accomodateBalls(position,mid,m))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
    public boolean accomodateBalls(int[] position, int mid, int balls)
    {
        int x = position[0], count = 1;
        for(int i = 1; i < position.length; i++)
        {
            if(position[i] - x >= mid)
            {
                count++;
                x = position[i];
            } 
            if(count == balls)
                return true;
        }
        return false;
    }
    
}