class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int[][] hs = new int[26][2];
        for(int i=0;i<26;i++){
            hs[i][0] = -1;
            hs[i][1] = -1;
        }
        int n = s.length();
        for(int i=0;i<n;i++){
            if(hs[(int)s.charAt(i)-97][0]==-1){
                hs[(int)s.charAt(i)-97][0]=i;
            }
            else{
                hs[(int)s.charAt(i)-97][1]=i;
            }
        }
        int max = -1;
        for(int i=0;i<26;i++){
            max = Math.max(max,hs[i][1]-hs[i][0]-1);
        }
        return max;
    }
}