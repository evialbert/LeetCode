//Greedy
class Solution {
    class Pair
    {
        int n,freq;
        Pair(int n,int freq)
        {
            this.n=n;
            this.freq=freq;
        }
    }
    public int minSetSize(int[] arr) {
        int max=0,n=arr.length;
        for(int i:arr)
        {
            max=Math.max(max,i);
        }
        int freq[]=new int[max+1];
        for(int i:arr)
        {
            ++freq[i];
        }
        PriorityQueue<Pair> pq=new PriorityQueue<Pair>((a,b)->b.freq-a.freq);
        for(int i=0;i<=max;i++)
        {
            if(freq[i]!=0)
                pq.add(new Pair(i,freq[i]));
        }
        int ans=0,size=0;
        while(!pq.isEmpty())
        {
            ++ans;
            Pair x=pq.poll();
            int times=x.freq;
            size+=times;
            if(size>=(n/2))
            {
                break;
            }
            
        }
        return ans;
        
    }
}