public class Solution {

    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length()){

            return false;

        }

        char[] ss = s.toCharArray();

        char[] tt = t.toCharArray();

        Arrays.sort(ss);

        Arrays.sort(tt);

        for(int i =0;i<ss.length;i++){

            if(ss[i]!=tt[i]){

                return false;

            }

            else{

                continue;

            }

        }

        return true;

    }

}