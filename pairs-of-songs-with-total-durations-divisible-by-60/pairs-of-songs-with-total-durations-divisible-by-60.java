class Solution {

    public int numPairsDivisibleBy60(int[] time) {

        //our goal in this problem is just to find total number of pairs

        //therefore number of pairs divisible by 60 is

        //(div 0) + (div 1) * (div 59) + (div 2) * (div 58) + .....



        int[] remainder = new int[60];

        int count = 0;

        for (int item: time) {

            remainder[(item + 60) % 60]++;

        }



        count += (remainder[0] * remainder[0] - remainder[0]) / 2;;

        count += (remainder[30] * remainder[30] - remainder[30]) / 2;



        for (int i = 1; i <= 29; i++) {

            count += remainder[i] * remainder[60-i];

        }

        return count;

    }

}