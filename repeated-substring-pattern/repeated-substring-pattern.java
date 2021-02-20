public class Solution {

    public boolean repeatedSubstringPattern(String str) {

        int len = str.length();



        for (int i = 1; i <= len/2; i++) {

            if (len % i == 0) {

                String attempt = new String(new char[len/i]).replace("\0", str.substring(0, i));



                if (attempt.equals(str)) {

                    return true;

                }

            }

        }

        

        return false;

    }

}