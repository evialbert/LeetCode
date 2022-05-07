class Solution {
   public int countStudents(int[] students, int[] sandwiches) {
        int ones = 0;
        int zeroes = 0;
        for(int student : students) {
            if(student == 0) zeroes++;
            else ones++;
        }
        for(int sandwich : sandwiches) {
            if(sandwich == 0) {
                if(zeroes == 0) return ones;
                zeroes--;
            } else {
                if(ones == 0) return zeroes;
                ones--;
            }
        }
        return 0;
    }
}