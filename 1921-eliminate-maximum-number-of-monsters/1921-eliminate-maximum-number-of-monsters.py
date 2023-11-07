class Solution:
    def eliminateMaximum(self, dist, speed):
        n = len(dist)

        for i in range(n):
            dist[i] = math.ceil(dist[i] / speed[i])
        dist.sort()

        i = 0
        for j in range(n):
            if i >= dist[j]:
                return i
            i += 1

        return n