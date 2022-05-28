class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        HashMap<Integer,Integer> hmap = new HashMap<>();
        for(int i=lowLimit;i<=highLimit;i++)
        {
            int pos = sumOfDigits(i);
            hmap.put(pos,hmap.getOrDefault(pos,0)+1);
        }
        int max = 0;
        for(int key:hmap.keySet())
            max = Math.max(max,hmap.get(key));
        return max;
    }
    public int sumOfDigits(int n)
    {
        if(n<=9)
            return n;
        return (n%10)+ sumOfDigits(n/10);
    }
}