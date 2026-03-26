class Solution:
    def minimumK(self, nums: List[int]) -> int:


        l = 1
        r = max(max(nums), len(nums))


        def check(el):

            sm = 0
            for i in range(len(nums)):
                # print(math.ceil(nums[i] / el), el)
                sm += math.ceil(nums[i] / el)

            if sm <= el * el:
                return True

        while l <= r:

            mid = (l + r) // 2

            if check(mid):
                r = mid - 1
            else:
                l = mid + 1

        return (l)
                