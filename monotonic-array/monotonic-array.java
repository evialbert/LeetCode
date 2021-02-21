class Solution {

    public boolean isMonotonic(int[] A) {

        int flag = 0;

        if (A.length == 1) {

            return true;

        } else if (A.length >= 2) {

            flag = A[1] - A[0];

        }

        for (int i = 0; i < A.length - 1; i++) {

           // System.out.println(flag);

            int tmp=isNegative(A[i + 1] - A[i]);

            if (isNegative(flag) * tmp >= 0) {

                if(tmp!=0){

                    flag =tmp;

                }

                

                continue;



            }

            return false;



        }

        return true;



    }



    private int isNegative(int num) {

        if (num < 0) {

            return -1;

        } else if (num > 0) {

            return 1;

        } else {

            return 0;

        }

    }
}
