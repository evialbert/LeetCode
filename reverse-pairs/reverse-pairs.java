class Solution {
    public int reversePairs(int[] nums) {
        return sort(nums, 0, nums.length - 1);
    }
    
    private int sort(int[] nums, int start, int end) {
        if (start >= end) {
            return 0;
        }
        
        int middle = (start + end) / 2;
        int answer = sort(nums, start, middle) + sort(nums, middle + 1, end);
        answer += merge(nums, start, middle, end);
        return answer;
    }
    
    private int merge(int[] nums, int start, int middle, int end) {
        int answer = 0;
        int i = start, j = middle + 1;
        
        while (i <= middle) {
            while (j <= end && nums[j] * 2l < nums[i]) {
                j++;
            }
            
            answer += j - middle - 1;
            i++;
        }
        
        i = start;
        j = middle + 1;
        int index = 0;
        int[] tmp = new int[end - start + 1];
        
        while (i <= middle && j <= end) {
            if (nums[i] <= nums[j]) {
                tmp[index++] = nums[i++];
            } else {
                tmp[index++] = nums[j++];
            }
        }
        
        while (i <= middle) {
            tmp[index++] = nums[i++];
        }
        
        while (j <= end) {
            tmp[index++] = nums[j++];
        }
        
        System.arraycopy(tmp, 0, nums, start, end - start + 1);
        return answer;
    }
}