class Solution:
    def __init__(self, m: int, n: int):
        self.n, self.len = n, m * n
        self.items = {}
        self.last_idx = self.len-1

    def flip(self) -> List[int]:
        idx = random.randint(0, self.last_idx)
        v = self.items.get(idx, idx)
        self.items[idx] = self.items.get(self.last_idx, self.last_idx)
        self.last_idx -= 1
        return divmod(v, self.n)

    def reset(self) -> None:
        self.items.clear()
        self.last_idx = self.len-1

# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()