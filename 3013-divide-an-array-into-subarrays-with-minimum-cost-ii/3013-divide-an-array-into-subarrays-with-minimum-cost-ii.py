class Solution:
    def minimumCost(self, nums, k, dist):
        from sortedcontainers import SortedList

        n, left, ans = len(nums), 1, SortedList()

        for i in range(1,dist+2):
            ans.add(nums[i])

        cur_sum = min_sum = sum(ans[:k-1])

        for right in range(dist+2,n):
            idx1 = ans.bisect_right(nums[right])

            if idx1 <= k-2:
                cur_sum -= ans[k-2]
                cur_sum += nums[right]

            ans.add(nums[right])

            idx2 = ans.bisect_left(nums[left])

            if idx2 >= k-1:
                ans.pop(idx2)
            else:
                cur_sum -= nums[left]
                cur_sum += ans[k-1]
                ans.pop(idx2)

            min_sum = min(min_sum,cur_sum)

            left += 1

        return nums[0] + min_sum
