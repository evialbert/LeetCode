class Solution {
     int min;
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
    
         min=Integer.MAX_VALUE;
        f(price,special,needs,0,0);
        return min;
        
    }
    
    public void f(List<Integer> p, List<List<Integer>> o, List<Integer> c,int i,int sum)
    {
         
        if(i==o.size())
        {
            for(int j=0;j<c.size();j++)
            sum+=(c.get(j)*p.get(j));
            min=Math.min(sum,min);
            return ;     
               
        }
        
        if(check(o.get(i),c))
        f(p,o,c,i+1,sum);
        else
        {
            
            ArrayList < Integer > clone = new ArrayList < >(c);
            int xy=gety(o.get(i),clone);
            f(p,o,clone,i,sum+xy);
            
            f(p,o,c,i+1,sum);
        }    
        
    }    
    
    public int gety(List<Integer> o,List<Integer> c)
    {
        int i;
        for(i=0;i<c.size();i++)
        c.set(i,c.get(i)-o.get(i));
        return o.get(i);
    }    
    
    
    public boolean check(List<Integer> o,List<Integer> c)
    {
        for(int i=0;i<c.size();i++)
        if(o.get(i)>c.get(i))
        return true;
        
        return false;
    }    
    
}