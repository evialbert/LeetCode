class Solution {
    public boolean winnerOfGame(String colors) {
        StringBuilder sb=new StringBuilder(colors); // it is not necessary
        int i=1;
        int aliceturns=0;
        int bobturns=0;
        while(i<sb.length()-1)
        {
            if (sb.charAt(i)=='A')
            {
                if (sb.charAt(i-1)=='A' && sb.charAt(i+1)=='A'){aliceturns++;}
            }
            else if (sb.charAt(i)=='B')
            {
                if (sb.charAt(i-1)=='B' && sb.charAt(i+1)=='B'){bobturns++;}
            }
            i++;
        }
        if (aliceturns<=bobturns){return false;}
        else{return true;}
    }
}