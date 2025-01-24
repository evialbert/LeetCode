class Solution:
    def countNonDecreasingSubarrays(self,nums, k):
        d = defaultdict(int)
        n = len(nums)
        res = n*(n+1)//2
        deq = deque()
        cursum = 0
        i = 0
        for j,num in enumerate(nums):
            while deq and nums[deq[-1]] < num:
                tmp = nums[deq.pop()]
                if deq:
                    d[deq[-1]] += (min(nums[deq[-1]],num)-tmp)*(j-deq[-1]-1)
            deq.append(j)
            cursum += max(nums[deq[0]]-num,0)
            while i < n and cursum > k:
                if deq and deq[0] == i:
                    left = deq.popleft()
                    d[left] += (nums[left]-max(num,nums[deq[0]]))*(j-left)
                res -= (n-j)
                cursum -= d[i]
                i += 1
        return res
            
            
            