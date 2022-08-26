class Solution {
    int[] stones;
    public boolean stoneGameIX(int[] stones) {
        this.stones = stones;
        int [] freq = new int[3];
        
        for (int i : stones) {
            if (i % 3 == 0) freq[0]++;
            else if (i % 3 == 1) freq[1]++;
            else freq[2]++;
        }
        
        boolean A = false;
        boolean B = false;
        int[] a = freq.clone();
        int[] b = freq.clone();
        if (a[1] > 0) {
            a[1]--;
            A = fun(a, 1);
        }
        if (b[2] > 0) {
            b[2]--;
            B = fun(b, 2);
        }
        return A || B ;
    }
    
    private boolean fun (int[] freq, int sum) {
        int n = stones.length;
        int i = 1;
        while (i < n) {
            if (i % 2 == 0) {   // alice turn
                if (sum % 3 == 1) {
                    if (freq[0] > 0) freq[0]--;
                    else if (freq[1] > 0) {
                        freq[1]--;
                        sum += 1;
                    } else return false;
                    
                } else if (sum % 3 == 2) {
                    if (freq[0] > 0) freq[0]--;
                    else if (freq[2] > 0) {
                        freq[2]--;
                        sum += 2;
                    }
                    else return false;
                }
                    
            } else {    // bob's turn
                if (sum % 3 == 2) {
                    if (freq[0] > 0) freq[0]--;
                    else if (freq[2] > 0) {
                        freq[2]--;
                        sum += 2;
                    }
                    else return true;
                    
                } else if (sum % 3 == 1) {
                    if (freq[0] > 0) freq[0]--;
                    else if (freq[1] > 0) {
                        freq[1]--;
                        sum += 1;
                    } else return true;
                }
            }
            i++;
        }
        return false;
    }
}