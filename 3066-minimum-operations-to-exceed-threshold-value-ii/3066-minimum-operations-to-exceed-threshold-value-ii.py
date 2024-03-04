class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        
        heapq.heapify(nums)
        count = 0

        while True:
            if len(nums) == 1:
                break

            num1 = heapq.heappop(nums)
            num2 = heapq.heappop(nums)

            if num1 >= k and num2 >= k:
                break

            heapq.heappush(nums, num1 * 2 + num2)
            count += 1
        
        return count
        