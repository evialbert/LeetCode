class Solution {

    public int reachNumber(int target) {

        target = target < 0 ? -target : target;

        int sum = 0, k = 0;

        while (sum < target) {

            sum += ++k;

        }

      

        if (((sum - target) & 1) == 0) {

            return k;

        }



        return k + 1 + (k & 1);

    }

}