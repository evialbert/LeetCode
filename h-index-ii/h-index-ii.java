public class Solution {
    public int hIndex(int[] citations) {
        
        int low = 0, high = citations.length-1;
        int res = 0;
        while(low<=high){
            
            int mid = low+(high-low)/2;
            System.out.println(mid);
            int h = citations.length-mid;
            System.out.println(h);
            if(citations[mid]>=h){
                res = h;
                high = mid-1;
            } else {
                low = mid+1;   
            }
        }
        
        return res;
    }
}