class Solution:
    def maxPoints(self, a: List[List[int]], queries: List[int]) -> List[int]:
        n = len(a)
        m = len(a[0])

        # flood-fill dijkstra
        queries = sorted(enumerate(queries), key=itemgetter(1))
        ret = [-1] * len(queries)

        mask = (1<<10) - 1

        # int-packing strategy
        heap = [a[0][0]<<20]
        a[0][0] = 0

        score = 0

        for idx, bound in queries:
            while heap and heap[0]>>20 < bound:
                j = heap[0] & mask
                i = (heappop(heap) >> 10) & mask

                score += 1

                for I, J in (i,j-1),(i,j+1),(i-1,j),(i+1,j):
                    if 0 <= I < n and 0 <= J < m and a[I][J]:
                        heappush(heap, (a[I][J]<<20) + (I<<10) + J)
                        a[I][J] = 0
            ret[idx] = score
        
        return ret