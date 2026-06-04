class Solution:
    def kthRemainingInteger(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        arr = []
        for i in range(len(nums)):
            if nums[i] % 2 == 0:
                arr.append(i)

        pre = []
        if arr:
            pre.append((nums[arr[0]] - 2) // 2)
        for i in range(len(arr) - 1):
            pre.append((nums[arr[i + 1]] - nums[arr[i]] - 2) // 2)
        for i in range(1, len(pre)):
            pre[i] += pre[i - 1]

        ans = []
        for l, r, k in queries:
            left = bisect_left(arr, l)
            right = bisect_right(arr, r) - 1
            if left >= len(arr) or right < 0:
                ans.append(2 * k)
                continue
            
            first = nums[arr[left]] // 2
            last = nums[arr[right]] // 2

            if k < first:
                ans.append(2 * k)
            elif last - right + left - 1 < k:
                k += right - left + 1
                ans.append(2 * k)
            else:
                k -= left
                idx = bisect_left(pre, k) - 1
                ans.append(nums[arr[idx]] + (k - pre[idx]) * 2)
        
        return ans