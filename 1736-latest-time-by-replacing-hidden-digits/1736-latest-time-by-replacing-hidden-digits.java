class Solution {
    public String maximumTime(String time) {
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<time.length();i++)
        {
            char c=time.charAt(i);
            if(c!='?')
                sb.append(c);
            else
            {
                if(i==0)
                {
                    if(time.charAt(1)-'0'>3 && time.charAt(1)-'0'<10)
                        sb.append(1);
                    else
                        sb.append(2);
                }
                else if(i==1)
                {
                    if(time.charAt(0)=='1' || time.charAt(0)=='0')
                        sb.append(9);
                    else
                        sb.append(3);
                }
                else if(i==3)
                    sb.append(5);
                else if(i==4)
                    sb.append(9);
            }
        }
        return sb.toString();
    }
}