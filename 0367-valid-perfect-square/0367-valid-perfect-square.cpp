class Solution {
public:
    bool isPerfectSquare(int x)
    {
        long long square = 1,start = 0, end = x,mid = (start + end)/2;
        bool ans = 0;
        while(start <= end)
        {
            mid = (start + end)/2;
            square = mid * mid;
            if(square == x)
            {
                ans = true;
                break;
            }
            else if(square > x)
            {
                end = mid - 1;
                
            }
        
            else if(square < x)
            {
                start = mid + 1;
            }
    }
        
        return ans;
    }    
    
};