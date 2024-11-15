class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n=a.size();
        if(n<=1) return 0;
        // Let's first calculate the longest increasing prefix and longest increasing suffix.
        int l,r;
        for(l=1;l<n;++l){
            if(a[l] < a[l-1]){
                break;
            }
        }
        for(r=n-1;r>=1;r--){
            if(a[r] < a[r-1]) {
                break;
            }
        }

        // overalpping
        l--;
        if(l>=r) return 0;

        /* 
        To calculate the minimum we have to calculate for each prefix what can be the suffix we can include and then calculate
        the length of the shortest subarray to be removed.

        Let's say there are two pointers i=l+1,j=r-1 which represents the current subarray to be removed. Check for each
        value of i and j, meaning each prefix and suffix and then calculate the valid subarray to removed and then calculate the ans.
        Takes n2 so use two pointers as both the left and right parts are sorted. or binary search to make it logn instead of n.
        */

        int mini = min(n-l-1,r);
        int i=0,j=r;
        while(i<=l and j<n){
            if(a[j] >= a[i]) mini=min(mini,j-i-1),i++;
            else j++;
        }
        return mini;
    }
};