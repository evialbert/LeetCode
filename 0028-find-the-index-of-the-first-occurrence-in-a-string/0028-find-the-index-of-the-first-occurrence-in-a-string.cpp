class Solution {
public:
    int strStr(string haystack, string needle)
    {
            if(needle.length() == 0)
            {
                return 0;
            }
        
            if(haystack.length()==2 && needle.length()==1)
            {
                if(haystack[0]==needle[0])return 0;
                return 1;
            }
        
        int j = 0,i = 0;
        for(i = 0; i<haystack.length();i++)
        {
            if(haystack[i] == needle[j])
            {
              
                j++;
            
                if(j == needle.length())
                {
                    return i-needle.length()+1;
                }
            
            }
           
            else
            {
               
                i=i-j+1;
                 j = 0;
                if(haystack[i] == needle[j])
                {
                    j++;
                }
               
              
            }
             
            
        }
    
        return -1;
        
        
    }
};