class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)==0:
            return False
        if len(nums)==1:
            if nums[0]==target:
                return True
            else:
                return False
        bigest_error = target - nums[0]
        if bigest_error>0:
            dir_flag = 1
        else:
            dir_flag = 0

        for i in range(0,len(nums)):
            error = target - nums[i]
            if error > bigest_error and dir_flag:
                return False
            if error == 0:
                return True
        return False