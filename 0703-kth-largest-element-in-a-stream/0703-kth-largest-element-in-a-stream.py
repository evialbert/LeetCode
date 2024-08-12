class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = nums
        heapq.heapify(self.pq)
        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)
        while len(self.pq) > self.k:
            heapq.heappop(self.pq)
        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)