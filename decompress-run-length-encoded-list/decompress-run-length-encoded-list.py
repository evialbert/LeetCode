class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        i = 0
        result = []
        # 0, 2, 4, 6... index element is the frequency
        # 1, 3, 5, 7... index element is the value

        # i will alaways be in even number
        # 0, 2, 4, 6
        # as we increment it by 2
        while i < len(nums):
            # Loop for nums[i] times (frequency)
            for j in range(nums[i]):
                # append nums[i+1] (value)
                result.append(nums[i+1])
            i += 2
        return result