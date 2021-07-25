class Solution {
    public int atMostNGivenDigitSet(String[] digits, int n) {
        int tmp = n, d = 0, cnt = 0, i = 0;
        LinkedList<Integer> ls = new LinkedList<>();
        while(tmp!=0)              // Count no. of digits
        {
            ls.addFirst(tmp%10); 
            tmp /= 10;
            d++;
        }
        for(int k=1; k<=d-1; k++)
            cnt += (int) Math.pow(digits.length,k);
        cnt += findInt(digits, d, ls);
        return cnt;
    }
    
    private int findInt(String digits[], int d, LinkedList<Integer> ls)
    {
        if(ls.size()==0) return 0;
        int i=0, cnt = 0;
        for(i=0; i<digits.length; i++)
            if(Integer.parseInt(digits[i])<ls.peekFirst())
                cnt += (int)Math.pow(digits.length,d-1);
            else break;
        if(i<digits.length && Integer.parseInt(digits[i])==ls.peekFirst())
        {
            if(ls.size()==1)
                cnt+=1;
            else{
                ls.removeFirst();
                cnt += findInt(digits, d-1, ls);
            }
        }
        return cnt;
    }
}