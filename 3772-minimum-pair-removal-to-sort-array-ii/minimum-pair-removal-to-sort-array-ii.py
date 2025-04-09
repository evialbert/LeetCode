class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        prev = [i - 1 for i in range(n)]
        asc = [int(i == 0 or nums[i] >= nums[i - 1]) for i in range(n)]
        asc_sum = sum(asc)
        next = [i + 1 for i in range(n)]
        next[-1] = -1
        heap = [(nums[i] + nums[i - 1], i) for i in range(1, n)]
        heapify(heap)

        def set_asc(i, x):
            nonlocal asc_sum
            asc_sum -= asc[i]
            asc[i] = x
            asc_sum += asc[i]
        
        count = 0
        while heap and asc_sum < n:
            x, i = heappop(heap)
            j = prev[i]
            if j == -1 or (nums[i] + nums[j] != x):
                continue
            
            if prev[j] != -1:
                next[prev[j]] = i
            prev[i] = prev[j]
            prev[j] = next[j] = -1
            nums[i] += nums[j]

            set_asc(j, 1)
            set_asc(i, int(prev[i] == -1 or nums[i] >= nums[prev[i]]))
            if next[i] != -1:
                set_asc(next[i], int(nums[next[i]] >= nums[i]))

            if prev[i] != -1:
                heappush(heap, (nums[i] + nums[prev[i]], i))
            if next[i] != -1:
                heappush(heap, (nums[i] + nums[next[i]], next[i]))

            count += 1
        return count