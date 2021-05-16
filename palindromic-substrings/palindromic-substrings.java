class Solution {
    public int countSubstrings(String s) {
        
        int count=0;
        for(int i=0 ; i<s.length() ; i++)
        {
            int x=i ;
            int y=i;
            
            while(x>=0 && y<=s.length()-1)
            {
                if(s.charAt(x)==s.charAt(y)) 
                {
                    count++;
                     x--;
                y++;
                }
                else break;
               
            }
            x=i;
            y=i+1;
             while(x>=0 && y<=s.length()-1)
            {
                if(s.charAt(x)==s.charAt(y)) 
                {
                    count++;
                     x--;
                y++;
                }
                else break;
               
            }
        }
        
        return count;
    }
}