class Solution {
    public long sumOfLargestPrimes(String str) {
        long n = str.length();
        // long arr[] = new long[(n * n+1) / 2 + 1];
        long sum = 0;
        long k = 0;
        List<Long> lst = new ArrayList<>();
        Set<Long> set = new TreeSet<>();

        for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(isPrime(Long.parseLong(str.substring(i,j))))
                    {
                        set.add(Long.parseLong(str.substring(i,j)));
                    }
                }
            }
        
        for(long i : set)
        {
            lst.add(i);
        }
        Collections.sort(lst);
        int s = lst.size();
        if(s>=3)
        {
            return lst.get(s-1) + lst.get(s-2) + lst.get(s-3);
        }
        else if(s==2)
        {
            return lst.get(s-1) + lst.get(s-2);
        }
        // sum += 
        // Arrays.sort(arr);
        // for(long i=0;i<arr.length;i++)
        // {
        //     System.out.prlongln(arr[i]);
        // }

        // System.out.prlongln(lst);
        return s!=0?lst.get(s-1):0;
        
            
    }
    public static boolean isPrime(long n)
    {
        if(n==1)return false;
        for(long i=2;i*i<=n;i++)
            {
                if(n%i==0)return false;
            }
        return true;
    }
}


