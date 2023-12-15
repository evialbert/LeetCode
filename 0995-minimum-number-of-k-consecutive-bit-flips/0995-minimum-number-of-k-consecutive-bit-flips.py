class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        ans = 0
        q = []
        for i in range(len(nums)):
            if len(q) % 2 == 0:
                if nums[i] == 0:
                    if i+k-1 <= len(nums)-1:
                        ans += 1
                        q.append(i+k-1)
                    else:
                        return -1
            else:
                if nums[i] == 1:
                    if i+k-1 <= len(nums)-1:
                        ans += 1
                        q.append(i+k-1)
                    else:
                        return -1
            if q:
                if q[0] == i:
                    q.pop(0)
        return ans