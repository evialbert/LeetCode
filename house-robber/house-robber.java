class Solution {
    public int rob(int[] num) {
        if (num.length == 0){
            return 0;
        }
        else{
            int with = num[0];
            int without = 0;
            for (int i = 1; i < num.length; i ++){
                int newWith = without + num[i];
                int newWithout = Math.max(with, without);
                with = newWith;
                without = newWithout;
            }
            return Math.max(with, without);
        }
    }
}