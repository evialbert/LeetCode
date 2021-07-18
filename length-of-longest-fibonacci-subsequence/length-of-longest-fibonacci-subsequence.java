class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n=arr.length;
        Map<Integer , Integer> map = new HashMap<>();
        int [][]mat = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i)
                    mat[i][j]=2;
            }
        }
        
        for(int i=0;i<n;i++)
            map.put(arr[i],i);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(j>i){ 
                int nel=arr[i]+arr[j];
                if(map.containsKey(nel))
                    mat[j][map.get(nel)]=mat[i][j]+1;
               } 
            }
        }
       int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=Math.max(ans,mat[i][j]);
            }
        }
        if(ans==2) return 0;
        return ans;
        
    }
}