class Solution {
    public String modifyString(String s) 
    {
        char c[] = s.toCharArray();
        
        for(int i=0;i<c.length;i++)
        {
            if(c[i]=='?')
            {
                char l='-';
                char r='-';
                
                if((i-1)>-1)l=c[i-1];
                if((i+1)<c.length)r=c[i+1];

				for(char c1='a'; c1<='z' ; c1++)
                {
                    if(c1!=l && c1!=r)
                    {
                        c[i]=c1;break;
                    }
                }
                
            }
            
        }
        return new String(c);
        
        
    }
}