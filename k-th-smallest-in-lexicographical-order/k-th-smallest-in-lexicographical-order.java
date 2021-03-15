 /**
     * for each subtree if it is complete tree
     * then the num of child is 11111....
     * so first find the root of each layer which is uncomplete and record the numbers of child
     */
 public class Solution {
    public int findKthNumber(int n, int k) {
        int m = 1, tmp=n/10;
        while (tmp>0) {
            tmp /= 10;
            m *= 10;
        }

        int firstPartNumber = count(m,n,m);

        if (k<=firstPartNumber) return findKthNumber(m,n,m,k);
        if (k<=n) return findKthNumber(n/10+1,m-1,m/10,k-firstPartNumber);
        
        return 0;
    }
    
    public int count(int start, int end, int flag) {
        // assume start and end has same amount of digits, flag represents the smallest number with the same length of digits, such as 10,100,1000,...
        int result = 0;
        while (flag>0) {
            result += (end/flag-start/flag+((start%flag==0)?1:0));
            flag /= 10;
        }
        return result;
    }
    
    public int findKthNumber(int start, int end, int flag, int k) {
        int left = start, right = end;
        // b-search
        while (left<=right) {
            int mid = (left+right)/2;
            int x = count(start,mid,flag);
            if (x==k) return mid;
            if (x<k)
                left=mid+1;
            else
                right=mid-1;
        }
        int t = right+1;
        int zeroToBedeleted = count(start,t,flag)-k;
        for (int i=0; i<zeroToBedeleted; i++)
            t /= 10;
        
        return t;
    }
}