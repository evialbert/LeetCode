class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        score, max_score = 0, 0
        up, down = 0, len(tokens) - 1
        tokens.sort()
        while up <= down:
            if tokens[up] <= power:
                score += 1
                power -= tokens[up]
                up += 1
            elif score > 0:
                score -= 1
                power += tokens[down]
                down -= 1
            else:
                return max_score
            max_score = max(score, max_score)
        return max_score