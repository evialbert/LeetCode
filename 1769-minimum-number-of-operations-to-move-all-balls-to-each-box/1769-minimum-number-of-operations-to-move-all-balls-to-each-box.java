class Solution {
   public int[] minOperations(String boxes) {
    int n=boxes.length();
    int ans[]=new int[n];
    int ball=0;
    int move=0;
    for(int i=0; i<n; i++){
        move+=ball;
        ball+=boxes.charAt(i)-'0';
        ans[i]=move;
    }
    ball=0;
    move=0;
    for(int i=n-1; i>=0; i--){
        move+=ball;
        ball+=boxes.charAt(i)-'0';
        ans[i]+=move;
    }
    return ans;
    
}
}