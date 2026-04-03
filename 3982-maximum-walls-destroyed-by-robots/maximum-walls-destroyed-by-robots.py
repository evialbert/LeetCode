class Solution:
    def maxWalls(self, robots: List[int], distance: List[int], walls: List[int]) -> int:
        n = len(robots)

        robots = sorted(zip(robots, distance))
        walls.sort()

        robots.append((10**18, 0))

        def count_walls(l, r):
            if l > r:
                return 0
            return bisect.bisect_right(walls, r) - bisect.bisect_left(walls, l)

        dp = [[0, 0] for _ in range(n)]

        pos, dist = robots[0]

        left_gain = count_walls(pos - dist, pos)
        right_gain = count_walls(pos, min(robots[1][0] - 1, pos + dist))

        dp[0][0] = left_gain
        dp[0][1] = right_gain

        for i in range(1, n):
            pos, dist = robots[i]
            prev_pos, prev_dist = robots[i - 1]


            left_l = max(pos - dist, prev_pos + 1)
            left_r = pos
            left_gain = count_walls(left_l, left_r)

            right_l = pos
            right_r = min(robots[i + 1][0] - 1, pos + dist)
            right_gain = count_walls(right_l, right_r)

            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + right_gain

            dp[i][0] = dp[i - 1][0] + left_gain

            overlap_l = left_l
            overlap_r = min(prev_pos + prev_dist, pos - 1)
            overlap = count_walls(overlap_l, overlap_r)

            dp[i][0] = max(dp[i][0], dp[i - 1][1] + left_gain - overlap)

        return max(dp[n - 1][0], dp[n - 1][1])