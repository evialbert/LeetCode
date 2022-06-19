class Solution {
    public int maxDistance(int[] n1, int[] n2) {
        int m=n1.length,n=n2.length,s=0;
        for(int i=0,j=0;j<n&&i<m;)
        {
            if(n1[i]>n2[j])
                i++;
            else
                s=Math.max(s,j++-i);
        }
        return s;
    }
}