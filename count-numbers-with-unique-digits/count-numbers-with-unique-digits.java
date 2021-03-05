class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        
        int ans=10;
        for(int i=2;i<=n;i++){
            int res=9;
            for (int j=2;j<=i;j++)
                res=res*(10-j+1);
            ans+=res;
        }
        
        return ans;
    }
}