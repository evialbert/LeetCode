class Solution {
    public int totalMoney(int n) {
        int count=1;
        int val=2;
        int sum=0;
        int wwe=7;
        for(int i=1;i<=n;i++)
        {
           if(i%7==0)
           {
               sum+=wwe++;
               count=val++;
           }
            else
            
                sum+=(count++);
            
        }
        
        return sum;
        
    }
}