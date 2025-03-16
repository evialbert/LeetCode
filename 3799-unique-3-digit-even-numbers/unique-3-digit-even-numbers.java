class Solution {
    public int totalNumbers(int[] digits) {
        int counter = 0;
        int[] freq = new int[10];

        for(int i : digits){
            freq[i]++;
        }

        for(int i = 100; i <1000 ; i++){
            int num = i;
            int digitA = num % 10;
            num = num/10;
            int digitB = num % 10;
            num = num/10;
            int digitC = num % 10;
            num = num/10;


            freq[digitA]--;
            freq[digitB]--;
            freq[digitC]--;

            if(i%2 == 0 && freq[digitA] >= 0 && freq[digitB] >= 0 && freq[digitC] >= 0 ){
                counter++;
            }
            freq[digitA]++;
            freq[digitB]++;
            freq[digitC]++;


        }



        return counter;
    }
}