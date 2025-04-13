class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        l  = len(nums)
        prev = [0, 0, 0]
        prev[0] = set([nums[-1]])
        prev[1] = set([0])
        prev[2] = set([nums[-1]])
        for i in range(l - 2, -1, -1):
            pres = prev.copy()
            pres[0].add(nums[i])
            for j in range(1, 3):
                for k in prev[j - 1]:
                    pres[j].add(nums[i] ^ k)
            prev = pres.copy()
        return len(prev[-1])
                