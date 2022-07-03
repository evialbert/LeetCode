class Solution {
   public boolean isThree(int n) {
        if(n<=3)
            return false;
        int count=0;
        for(int i=2;i<=(n/2);i++)
        {
            if(n%i==0)
                count++;    
        }
        //we need only one more divisor as one and the number itself are always the divisor.
        if(count==1)
                return true;
        return false;
    }
}