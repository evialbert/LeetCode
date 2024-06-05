class Solution {
    public int minimumChairs(String s) {
        int available_chair=0,required_chair=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='E')
            {
                if(available_chair>0)
                {
                    available_chair--;
                }
                else
                {
                    required_chair++;
                }
            }
            else
            {
              available_chair++;  
            }

        }

        return required_chair;
    }
}