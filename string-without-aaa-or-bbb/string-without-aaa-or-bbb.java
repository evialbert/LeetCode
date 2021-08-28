class Solution {
    class CharCount{
        int count;
        char c;
        CharCount(char c,int count){
            this.count=count;
            this.c=c;
        }
    }
    public String strWithout3a3b(int a, int b) {
        StringBuilder sb=new StringBuilder();
        PriorityQueue<CharCount> pq=new PriorityQueue<>((x,y)->y.count-x.count);
        if(a!=0) pq.add(new CharCount('a',a));
        if(b!=0) pq.add(new CharCount('b',b));
        int i=0;
        while(pq.size()!=0){
            CharCount c1=pq.poll();
            if(i>=2 && c1.c==sb.charAt(i-1) && c1.c==sb.charAt(i-2)){
                if(pq.size()==0)
                    break;   
                CharCount c2=pq.poll();
                sb.append(c2.c);
                c2.count--;
                if(c2.count>0)
                    pq.add(c2);
                i++;
            }
            sb.append(c1.c);
            i++;
            c1.count--;
            if(c1.count>0)
                pq.add(c1);
        }
        return sb.toString();
    }
}