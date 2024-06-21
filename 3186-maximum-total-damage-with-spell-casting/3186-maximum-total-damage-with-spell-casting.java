class Solution {
    public long maximumTotalDamage(int[] p) {
      int n=p.length;
      TreeMap<Integer,Long> mp=new TreeMap<>();
      for(int i:p){
        mp.put(i,mp.getOrDefault(i,0L)+1L);
      }  
      ArrayList<Integer> ll=new ArrayList<>();
      long[] dp=new long[mp.size()];
    long ans=0; int prev=0,i=0;
      for(int key:mp.keySet()){
        int myprev=-1;
       if(ll.size()>0) myprev=lower(ll,key-2);
       if(myprev!=-1) dp[i]=Math.max(dp[prev],((long)key*mp.get(key))+dp[myprev]);
       else dp[i]=Math.max(dp[prev],key*mp.get(key));
       prev=i;
        ll.add(key);
        ans=Math.max(ans,dp[i]);
        i++;
      }
      return ans;
    }
    public int lower(ArrayList<Integer>ll,int t){
        long l=0,h=ll.size()-1,ans=-1;
        while(l<=h && l<ll.size() && h>=0
        ){
            long m=h+(l-h)/2;
            if(ll.get((int)m)<t){
                ans=m; l=m+1;
            }
            else h=m-1;
        }
        return (int)ans;
    }
    
}