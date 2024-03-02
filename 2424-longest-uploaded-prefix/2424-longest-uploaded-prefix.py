class LUPrefix:
    def __init__(self, n: int):
        self.n = n
        self.ds = [0]*n

    def upload(self, video: int) -> None:
        left = right = 0
        video -= 1
        if video > 0: 
            left = self.ds[video-1]
        if video < self.n-1:
            right = self.ds[video+1]
        # join both left & right windows to form the length of current window
        self.ds[video] = left+right+1 
        # update leftmost & rightmost endpoints in the window
        self.ds[video-left] = self.ds[video]
        self.ds[video+right] = self.ds[video]

    def longest(self) -> int:
        return self.ds[0]

# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()