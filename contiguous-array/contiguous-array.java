class Solution {
    public int findMaxLength(int[] arr) {
        int ans=0;
        Map<Integer,Integer> mp=new HashMap<>();
        mp.put(0,-1);
        int sum=0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]==0){
                sum=sum-1;
            }
            else{
                sum=sum+1;
            }
            if(mp.containsKey(sum)){
                int idx=mp.get(sum);
                int len=i-idx;
                ans=Math.max(len,ans);
                    
            }
            else{
                mp.put(sum,i);
            }
        }
        return ans;
    }
}