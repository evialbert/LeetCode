class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int l = A.length;
        if(l<=2)return 0;
        int ans = 0, tmp = A[1]-A[0], cnt=0;
        for(int i=2; i<l; i++){
            if(A[i]-A[i-1]==tmp)cnt++;
            else {
                tmp = A[i]-A[i-1];
                ans += cnt*(cnt+1)/2;
                cnt = 0;
            }
        }
        return ans + cnt*(cnt+1)/2;
    }
}