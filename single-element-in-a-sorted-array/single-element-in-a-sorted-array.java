class Solution {
       public int singleNonDuplicate(int[] nums)
    {
        return _binarySearch(nums, 0, nums.length - 1);
    }

    /*
      All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …).
      And all elements after the required elements have the first occurrence at odd index and next occurrence at even index.
    */
    private int _binarySearch(int[] nums, int start, int end)
    {
        if (start > end)
            return 0;
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;
         /*
             If number is even,repeat element is mid+1 -> Means search after mid
             Else before mid
          */

        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
                return _binarySearch(nums, mid + 2, end);
            else
                return _binarySearch(nums, start, mid);
        }
           /*
             If number is odd,repeat element is mid-1 -> Means search after mid
             Else before mid
          */
        else
        {
            if (nums[mid] == nums[mid - 1])
                return _binarySearch(nums, mid + 1, end);
            else
                return _binarySearch(nums, start, mid-1);
        }

    }
}