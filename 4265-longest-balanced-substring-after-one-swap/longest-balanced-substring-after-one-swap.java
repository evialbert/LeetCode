class Solution {
    public int d(String s) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int one=0,zero=0,freqone=0,freqzero=0,ans=0;
        int n=s.length();
        map.put(0,-1);
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='1') freqone++;
            else freqzero++;
        }
        for(int i=0;i<n;i++){ 
            char ch=s.charAt(i);
            if(ch=='1') one++;
            else zero++;
            if(map.containsKey(one-zero+2)){
                int len=i-map.get(one-zero+2);
                if(freqone>=len/2&&freqzero>=len/2) ans=Math.max(ans,len);
            }
            if(map.containsKey(one-zero-2)){
                 int len=i-map.get(one-zero-2);
                if(freqone>=len/2&&freqzero>=len/2) ans=Math.max(ans,len);
            }
             if(map.containsKey(one-zero)){
                int len=i-map.get(one-zero);
               ans=Math.max(ans,len);
            }
              if(!map.containsKey(one-zero)) map.put(one-zero,i);
        }
        return ans;
    }
     public int longestBalanced(String s) {
         int ans=0;
         ans=Math.max(ans,d(s));
         StringBuilder sb=new StringBuilder();
         sb.append(s);
         ans=Math.max(ans,d(sb.reverse().toString()));
         return ans;
     }
}