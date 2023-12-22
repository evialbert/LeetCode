class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n = len(cookies)
        bucket = [0]*k
        def distribute(i= 0):
            nonlocal bucket
            ans = sys.maxsize
            visited = set()
            if i == n:
                return max(bucket)
            
            for j in range(k):
                if bucket[j] in visited:
                    continue
                visited.add(bucket[j])
                bucket[j]+=cookies[i]
                if max(bucket)<ans:
                    ans = min(ans,distribute(i+1))
                bucket[j]-=cookies[i]
            return ans
        cookies.sort(reverse = True)
        return distribute(0)