class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)  # Total number of questions
        dp = [0] * (n + 1)  # DP array initialized with zeros

        # Process questions from last to first (reverse order)
        for i in range(n-1, -1, -1):
            points, br_pw = questions[i]  # Extract points and brainpower
            nxt_idx = i + br_pw + 1  # Next available question after solving this one

            # If we solve this question, we get "points" + max points from "nxt_idx" onwards
            take = points + (dp[nxt_idx] if nxt_idx < n else 0)

            # If we skip this question, we take the max points from the next question onwards
            skip = dp[i + 1]

            # Store the best choice
            dp[i] = max(take, skip)

        # The first element of dp array gives the answer: max points starting from question 0
        return dp[0]