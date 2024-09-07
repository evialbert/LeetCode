class Solution {
    public boolean checkTwoChessboards(String a, String b) {
        int x1 = a.charAt(0) - 'a', y1 = a.charAt(1);
        int x2 = b.charAt(0) - 'a', y2 = b.charAt(1);

        int color1 = -1, color2 = -1;
        if (x1 % 2 == 0) {
            if (y1 % 2 == 0) {
                color1 = 0;
            } else {
                color1 = 1;
            }
        } else {
            if (y1 % 2 == 0) {
                color1 = 1;
            } else {
                color1 = 0;
            }
        }
        if (x2 % 2 == 0) {
            if (y2 % 2 == 0) {
                color2 = 0;
            } else {
                color2 = 1;
            }
        } else {
            if (y2 % 2 == 0) {
                color2 = 1;
            } else {
                color2 = 0;
            }
        }
        return color1 == color2;
    }
}