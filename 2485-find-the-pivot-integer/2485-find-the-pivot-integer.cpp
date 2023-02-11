class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n*(n+1))/2;
        int temp = 0;
        int ans = -1;
        for(int i=1; i<=n; i++)
        {
            sum = sum -i;
            if(sum==temp)
            {
                ans=i;
                break;
            }
            temp = temp + i;
        }
        return ans;
    }
};