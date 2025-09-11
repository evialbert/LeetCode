class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)

        # Build prime edges by using prime factorization
        prime_to_i = defaultdict(list)
        for i, num in enumerate(nums):
            d = 2
            tmp = num
            while d * d <= tmp:
                if tmp % d == 0:
                    prime_to_i[d].append(i)
                    while tmp % d == 0:
                        tmp //= d
                d += 1
            if tmp > 1:
                prime_to_i[tmp].append(i)

        # Simple Dijkstra
        distances = [inf] * n
        distances[0] = 0
        heap = [(0, 0)]
        while heap:
            dist, u = heappop(heap)
            if dist > distances[u]:
                continue

            # Jump backward
            if u - 1 >= 0 and distances[u - 1] > dist + 1:
                distances[u - 1] = dist + 1
                heappush(heap, (dist + 1, u - 1))

            # Jump forward
            if u + 1 < n and distances[u + 1] > dist + 1:
                distances[u + 1] = dist + 1
                heappush(heap, (dist + 1, u + 1))

            # Teleport if current is a prime
            if nums[u] in prime_to_i:
                for v in prime_to_i[nums[u]]:
                    if v != u:
                        if distances[v] > dist + 1:
                            distances[v] = dist + 1
                            heappush(heap, (dist + 1, v))
                del prime_to_i[nums[u]]
        return distances[-1]