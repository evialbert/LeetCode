class BIT:
    def __init__(self,n):
        self.ans = [0]*(n+1)

    def query(self,i):
        res = 0
        while i > 0:
            res += self.ans[i]
            i -= i&-i
        return res

    def update(self,i,val):
        while i < len(self.ans):
            self.ans[i] += val
            i += i&-i

class Solution:
    def goodTriplets(self, nums1, nums2):
        dict1 = {x:i for i,x in enumerate(nums1)}
        n = len(nums1)
        arr = [dict1[nums2[i]] for i in range(n)]

        BIT1, BIT2, total = BIT(n), BIT(n), 0

        for i in arr:
            total += BIT2.query(i)
            BIT1.update(i+1,1)
            less = BIT1.query(i)
            BIT2.update(i+1,less)

        return total









        