class Solution {
     public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            switch (i) {
                case 5:
                    five++;
                    break;
                case 10:
                    ten++;
                    five--;
                    break;
                case 20:
                    if (ten > 0) {
                        ten--;
                        five--;
                    } else five -= 3;
            }
            if (five < 0) return false;
        }
        return true;
    }
}
