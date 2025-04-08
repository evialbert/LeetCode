class Solution:

    def __init__(self, w: List[int]):
        sum_w = sum(w)
        self.n = len(w)

        # Get the PDF
        self.pdf = [float(v/sum_w) for v in w]

        # Get the CDF
        self.cdf = [0]*self.n
        self.cdf[0] = self.pdf[0]
        for idx in range(1, self.n):
            self.cdf[idx] = self.cdf[idx-1] + self.pdf[idx]


    def pickIndex(self) -> int:
        # Sample u from [0,1]
        random_number = random.random()

        # Return the smallest i such that cdf(x) >= u 
        return bisect.bisect(self.cdf, random_number)


    

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()