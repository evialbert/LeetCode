public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int oneArea = (C-A)*(D-B);
        int twoArea = (G-E)*(H-F);
        int left = Math.max(A,E);
        int right = Math.min(C,G);
        int top = Math.min(D,H);
        int bottom = Math.max(B,F);
        int cover = 0;
        if(left<right && bottom<top){
            cover = (right-left)*(top-bottom);
        }
        return oneArea + twoArea - cover;
    }
}