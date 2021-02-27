/*using Binary search
*/
class Solution {
    public List<Integer> countSmaller(int[] nums) {
        
        List<Integer> helper = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        
        for(int i = n-1;i>=0;i--){
            int s = bs(helper,nums[i]);
            ans.add(s);
            helper.add(s,nums[i]);
        }
        Collections.reverse(ans);
        return ans;
    }
    int bs(List<Integer> arr,int val){
        int si = 0 , ei = arr.size();
        while(si < ei){
            int mid = si + (ei-si)/2;
            if(arr.get(mid) < val) si = mid+1;
            else ei = mid;
        }
        return si;
    }
}