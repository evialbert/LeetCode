class Solution {
    private void update(int[] freq,int num){
        for(int i=0;i<32;i++){
            if(((num>>i)&1)==1){
                freq[i]++;
            }
        }
    }
    
    private int compare(int[] f,int num,int c,int k){
        for(int i=0;i<32;i++){
            if(((num>>i)&1)==1 && f[i]==1){
                    c &= ~(1<<i);
                    if(c<k)return k-1;
            }
        }
        return c;
    }
    
    private void remove(int[] freq,int num){
        for(int i=0;i<32;i++){
            if(((num>>i)&1)==1){
                freq[i]--;
            }
        }
    }
    
    public int minimumSubarrayLength(int[] nums, int k) {
        int l=0;
        int n=nums.length;
        int c=0,ans=Integer.MAX_VALUE;
        int[] freq = new int[32];
        for(int r=0;r<n;r++){
            c |= nums[r];
            update(freq,nums[r]);
            if(c>=k){
                while(l<r){
                    int comp = compare(freq,nums[l],c,k);
                    if(comp>=k){
                        c=comp;
                        remove(freq,nums[l]);
                        l++;
                    }else{
                        break;
                    }
                }
                ans = Math.min(ans,(r-l+1));
            }
        }
        return (ans==Integer.MAX_VALUE)?-1:ans;
    }
}

