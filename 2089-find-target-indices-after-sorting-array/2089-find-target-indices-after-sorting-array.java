class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> list = new ArrayList<>();
        if (nums.length == 1 && nums[0]!= target) {
            return list;
        }
        Arrays.sort(nums);
        addTargetIndex(nums,target,list);
        Collections.sort(list);
        return list;    
    }
    
    void addTargetIndex(int[] nums, int target, List<Integer> list){
        int start = 0;
        int last = nums.length - 1;
        int mid = -1 ;
        while (start <= last) {
            mid = start + (last - start) / 2;
            if (nums[mid] == target) {
                break;
            }else if (nums[mid] < target) {
                start = mid + 1;
            }else {
                last  = mid - 1;
            }
        }
        int counter = mid-1;
         while ((counter >=0 && counter < nums.length ) && nums[counter] == target) {
            list.add(counter);
            counter--;
        } 
        counter = mid;
        while ((counter >=0 && counter < nums.length ) && nums[counter] == target) {
            list.add(counter);
            counter++;
        }  
    }
}