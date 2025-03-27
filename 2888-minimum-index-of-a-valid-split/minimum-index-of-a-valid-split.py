class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        dominant = self.find_dominant(nums)

        idx = dominant_count = 0
        for i, n in enumerate(nums):
            if n == dominant:
                dominant_count += 1
            
            if dominant_count > (i + 1) // 2:
                idx = i
                break

        dominant_count = 0
        for j in range(idx + 1, len(nums)):
            if nums[j] == dominant:
                dominant_count += 1

        if (len(nums) - idx - 1) // 2 >= dominant_count:
            return -1
        else:
            return idx



    def find_dominant(self, nums):
        candidate = None
        counter = 1

        for n in nums:
            if not candidate:
                candidate = n
            elif n == candidate:
                counter += 1
            else:
                counter -= 1
                if counter == 0:
                    candidate = n
                    counter = 1
        
        return candidate
