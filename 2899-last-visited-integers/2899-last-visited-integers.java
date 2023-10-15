class Solution {
    public List<Integer> lastVisitedIntegers(List<String> arr) {

        List<Integer> nums = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();

        int count = -1;

        for(int i=0; i<arr.size(); i++){
            if(arr.get(i).equals("prev")){
                if(count==-1) ans.add(-1);
                else ans.add(nums.get(count--));
            }else{
                int a = 0;
                String s = arr.get(i);
                for(int j=0; j<s.length(); j++){
                    a *= 10;
                    a += (s.charAt(j)-'0');
                }
                count = nums.size();
                nums.add(a);
            }
        }
        return ans;
    }
}