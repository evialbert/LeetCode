class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) { // N^3
        // bit operation, bitwise AND, then count bit
        int[] bits1 = bitwise(img1);
        int[] bits2 = bitwise(img2);
        int n = img1.length;
        int res = 0;
        for (int hori = -1 * n + 1; hori < n; hori ++) {
            for (int veti = -1 * n + 1; veti < n; veti ++) {
                int curOverLapping = 0;
                if (veti < 0) { // moving upwards
                    for (int i = -1 * veti; i < n; i ++) {
                        if (hori < 0) { // moving leftwards
                            curOverLapping += Integer.bitCount((bits1[i] << -1 * hori) & bits2[i - -1 * veti]);
                        } else { // moving rightwards
                            curOverLapping += Integer.bitCount((bits1[i] >> hori) & bits2[i - -1 * veti]);
                        }
                    }
                } else { // moving downwards
                    for (int i = 0; i < n - veti; i ++) {
                        if (hori < 0) { // moving leftwards
                            curOverLapping += Integer.bitCount((bits1[i] << -1 * hori) & bits2[veti + i]);
                        } else { // moving rightwards
                            curOverLapping += Integer.bitCount((bits1[i] >> hori) & bits2[veti + i]);
                        }                        
                    }
                }
                res = Math.max(res, curOverLapping);
            }
        }
        return res;
    }
    
    private int[] bitwise(int[][] img) {
        int[] bits = new int[img.length];
        for (int i = 0; i < img.length; i ++) {
            int cur = 0;
            for (int j = 0; j < img[0].length; j ++) {
                cur = cur * 2 + img[i][j];
            }
            bits[i] = cur;
        }
        return bits;
    }
}