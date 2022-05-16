class Solution {
    public int[] decode(int[] encoded, int first) {
        int[] ans = new int[encoded.length+1];
        ans[0]=first;
        int temp=0;
        for(int i=0;i<encoded.length;i++){
            temp = first^encoded[i];
            ans[i+1]= temp;
            first = temp;
            
        }
        return ans;
    }
}