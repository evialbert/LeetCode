class Solution {
    public int reinitializePermutation(int n) {
        int[] perm = new int[n];
        
        for(int i=0; i<n; i++)
            perm[i] = i;
        
        int ops = n;
        int count = 0;
        while(ops != 0){
            int[] arr = new int[n];
            
            for(int i=0; i<n; i++){
                if(i%2 == 0)
                    arr[i] = perm[i/2];
                else
                    arr[i] = perm[n/2 + (i-1)/2];
            }
                count++;
                
                if(arr[1] == 1)
                    break;
                
                perm = Arrays.copyOf(arr, n);
                ops--;
            }
        return count;
    }
}