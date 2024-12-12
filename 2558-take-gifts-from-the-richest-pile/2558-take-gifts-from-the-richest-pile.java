class Solution {
    public long pickGifts(int[] gifts, int k) {
        int l = gifts.length;
        for(int i=1; i<=k; i++)
        {
            Arrays.sort(gifts);                      // Sort before each operation
            gifts[l-1]=(int)Math.sqrt(gifts[l-1]);   //Operation on max element
        }
        long sum=0;
        for(int i:gifts)                  // Iterate over the elements    
        {                                 // of pq and add to sum
            sum+=i;
        }
        return sum;
    }
}