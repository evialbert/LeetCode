class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        List<Integer> result = new ArrayList<>();
        if(nums.length == 0) return result;
        List<List<Integer>> subsets = new ArrayList<>();
        for(int i=0;i<nums.length;i++) {
            int maxLengthIndex = i;
            List<Integer> subset = new ArrayList<>();
            subsets.add(subset);
            for(int j=0;j<=i;j++)
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0)
                    if(subsets.get(j).size() +1 > subsets.get(maxLengthIndex).size()) maxLengthIndex = j;
            subset.addAll(subsets.get(maxLengthIndex));
            subset.add(nums[i]);
            
            if(subset.size()>result.size())
                result = subset;
        }
        return result;
    }
}