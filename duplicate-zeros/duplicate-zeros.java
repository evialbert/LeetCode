class Solution {

    public void duplicateZeros(int[] arr) {

        int[] copy = new int[arr.length];

        System.arraycopy(arr, 0, copy, 0, arr.length);

        int cur = 0;

        for (int i = 0; cur < arr.length && i < arr.length; ++cur, ++i) {

            arr[cur] = copy[i];

            if (copy[i] == 0 && ++cur < arr.length) {

                arr[cur] = 0;

            }

        }

    }

}