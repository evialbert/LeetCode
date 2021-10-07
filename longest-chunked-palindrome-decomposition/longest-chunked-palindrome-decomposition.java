class Solution {
  public int longestDecomposition(String text) {
        return decomposition(text,0,text.length()-1,0);
    }
    public int decomposition(String text,int left,int right,int ans){
        if(left>right) return 0;
        if(left==right) return 1;
        for(int gap=0; gap<right; gap++){
            int rightBoundOfLeft= left+gap;
            int leftBoundOfRight= right-gap;
            if(leftBoundOfRight<=rightBoundOfLeft) return ans+1;
            if(check(text,left,rightBoundOfLeft,leftBoundOfRight,right)) 
                return 2 + decomposition(text,rightBoundOfLeft+1,leftBoundOfRight-1,ans);
        }
        return 1;
    }
    public boolean check(String text,int left1,int left2,int right1,int right2){
        for(int i=0; i<left2-left1+1; i++){
            if(text.charAt(left1+i)!=text.charAt(right1+i)) return false;
        }
        return true;
    }
}