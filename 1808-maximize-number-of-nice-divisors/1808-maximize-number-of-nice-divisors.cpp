class Solution {
public:
    
int power(long long x, unsigned int y, int p)
{
    int res = 1;
    
    x = x % p;
  
    if (x == 0) 
        return 0;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        
        y = y>>1;
        x = (x*x) % p;
    }
    
    return res;
}
    
    int maxNiceDivisors(int pf) {
        if(pf==1)
            return 1;
        
        long ans = 1, M=1e9+7;
        
        int div = pf/3;
        int rem = pf%3;
        
        if(rem==1)
            div--;
        
        ans = power(3, div, M)%M;
        
        if(rem==2)
            return (ans*2)%M;
        
        if(rem==4 || rem==1)
            return (ans*4)%M;
        
        return ans;
    }
};