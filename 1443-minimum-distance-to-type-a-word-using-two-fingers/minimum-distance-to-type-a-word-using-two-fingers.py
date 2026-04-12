class Solution:
    def minimumDistance(self, word: str) -> int:
        # Precompute coordinates for A-Z (0-25)
        pos = [(i // 6, i % 6) for i in range(26)]
        
        # Precompute distances between all letters (plus index 26 for unused finger)
        dist = [[0] * 27 for _ in range(27)]
        for i in range(26):
            xi, yi = pos[i]
            for j in range(26):
                xj, yj = pos[j]
                dist[i][j] = abs(xi - xj) + abs(yi - yj)
        # dist[26][*] = 0 (unused finger moves for free)
        
        n = len(word)
        # Convert word to integer indices
        chars = [ord(c) - 65 for c in word]
        
        # dp[other] = min cost after last char typed, with other finger at 'other' (0-26)
        INF = 10**9
        dp = [0] * 27  # Initially, any position for the other finger costs 0 (free placement)
        last = chars[0]
        
        for target in chars[1:]:
            new_dp = [INF] * 27
            d_lt = dist[last][target]
            for other in range(27):
                cost = dp[other]
                if cost == INF:
                    continue
                # Option 1: continue with same finger (finger at last)
                if cost + d_lt < new_dp[other]:
                    new_dp[other] = cost + d_lt
                # Option 2: switch to other finger
                if other == 26:
                    new_cost = cost  # free initial placement
                else:
                    new_cost = cost + dist[other][target]
                if new_cost < new_dp[last]:
                    new_dp[last] = new_cost
            dp = new_dp
            last = target
        
        return min(dp)