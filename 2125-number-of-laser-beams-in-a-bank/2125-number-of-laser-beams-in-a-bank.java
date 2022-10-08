class Solution {
   public int numberOfBeams(String[] b) {
    int k=b.length,p=0,s=0;
    for(int i=0;i<b[0].length();i++)
    {
        if(b[0].charAt(i)=='1')
            p++;
    }
    for(int i=1;i<k;i++)
    {
        if(!(b[i].contains("1")))
            continue;
        else
        {
            int h=0,f=b[i].length();
            for(int j=0;j<f;j++)
            {
                if(b[i].charAt(j)=='1')
                    h++;
            }
            s=s+(p*h);
            p=h;
        }
    }
    return s;
}
}