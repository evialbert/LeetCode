class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:

        cache = Counter()
        ans=0

        for h in hours:
            rem=h%24
            ans+=cache[(24-rem)%24]
            cache[rem]+=1

        return ans