typedef unsigned long long ull;
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
   
    ull beg=1, end = 2e18, mid;
	    while(beg <= end){
	        mid = (beg+end)>>1;
	        ull count = uglyLessThan(mid, a, b, c);
	      
	       // if(count == n) rejected this because even if count == n but mid may not be an ugly number.
	         //   return mid;
	       if(count >= n)//for Ex 1 : 2,3,4,5,6,7,8,9,10. But 7 is not an ugly number as it's not divisible by 2 or 3 or 5 but aur algo can land on 7 and here the count will be greater than required and thus we go left side
	            end = mid -1;
	       else
	            beg = mid+1;
	    }
	return beg;
	}
	ull uglyLessThan(ull mid, ull a, ull b, ull c){
	    ull count = mid/a + mid/b + mid/c - (mid/(lcm(a,b)) + mid/(lcm(b,c)) + mid/(lcm(c,a))) + (mid/lcm(a,lcm(b,c)));
	    return count;
	}
    ull lcm(ull a, ull b){
        return a*b/(gcd(a,b));
    }
    ull gcd(ull a, ull b){
        if(a == 0)
            return b;
        if(b == 0)
            return a;
        ull x = max(a,b), y = min(a,b);
        return gcd(x%y, y);
    }

};