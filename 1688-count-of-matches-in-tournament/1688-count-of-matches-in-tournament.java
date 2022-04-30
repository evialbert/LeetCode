class Solution {
    public int numberOfMatches(int n) {
        int matches=0;
        int teams=0;
        while(n!=1)
        {
            if(n%2!=0)
            {
                matches+=(n-1)/2;
                teams=((n-1)/2)+1;
                n=teams;
            }
            else
            {
                matches+=n/2;
                teams=n/2;
                n=teams;
            }
        }
        
        return matches;
        
        
    }
}