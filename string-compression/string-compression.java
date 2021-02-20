class Solution {
    public int compress(char[] chars) {
        char prev = chars[0];
        int num=1;
        int newLen=0;

        for(int i=1;i<chars.length;i++)
        {
            if(chars[i]==prev)
                num++;
            else
            {
                if(num>1)
                {
                    chars[newLen++]=prev;
                    if(num/10>0)
                        chars[newLen++]=(char) ((int)(num/10)+48);
                    chars[newLen++]=(char) ((int)(num%10)+48);
                }
                else
                    chars[newLen++]=prev;
                num=1;
                prev=chars[i];
            }
        }

        if(num>1)
        {
            chars[newLen++]=prev;
            if(num/10>0)
                chars[newLen++]=(char) ((int)(num/10)+48);
            chars[newLen++]=(char) ((int)(num%10)+48);
        }
        else
            chars[newLen++]=prev;

        return newLen;
    }
}