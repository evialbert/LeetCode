class Solution
{
    public int maximumEnergy(int[] energy, int k)
    {
        int l = energy.length;
        
        for(int i=l-k-1; i>=0; i--)
            energy[i] += energy[i+k];

        int r = Integer.MIN_VALUE;

        for(int i=0; i<l; i++)
            r = Math.max(r,energy[i]);

        return r;
    }
}