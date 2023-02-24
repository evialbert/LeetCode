/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int f(int l , int h)
    {
        int x=l , y=h ;
        int mid = y + (x-y)/2 ;
        return mid ;
    }
    int guessNumber(int n) {
        int l=1 , h=n ;
        while(1)
        {
            int mid = f(l,h) ;
            int r = guess(mid) ;        
            if(r == 0)  return mid ;
            else if(r == 1) l=mid+1 ;
            else  h=mid-1 ;
        }
    }
};