class Solution {
    public int findMinFibonacciNumbers(int k) {
       int a=1,b=1,c=0,ta=0;
       while(c<k){
           c=a+b;
           ta=a;
           a=b;
           b=c;
       }
       int ans=0;
       if(c==k)
            return 1;
       b=a;a=ta;
       //System.out.println(a+" "+b+" "+c);
       while(c>=1 && k>0){
           //System.out.println(k);
           if(k>=c){
               k=k-c;
               ans++;
           }
           ta=b-a;
           c=b;
           b=a;
           a=ta;
       }
        return ans;
    }
}