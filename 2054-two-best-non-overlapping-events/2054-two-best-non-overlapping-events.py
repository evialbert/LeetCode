class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1])
        n = len(events)
        maxValue = [0] * n
        maxValue[0] = events[0][2]
        for i in range(1, n):
            maxValue[i] = max(maxValue[i - 1], events[i][2])
        maxSum = 0
        for i in range(n):
            low, high, idx = 0, i - 1, -1
            while low <= high:
                mid = (low + high) // 2
                if events[mid][1] < events[i][0]:
                    idx = mid
                    low = mid + 1
                else:
                    high = mid - 1
            maxSum = max(maxSum, events[i][2] + (maxValue[idx] if idx != -1 else 0))
        return maxSum