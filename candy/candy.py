class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        dp = [1 for i in range(n)]
        for i in range(1 , n - 1):
            left_val = right_val = 0
            if ratings[i] > ratings[i - 1]:
                left_val = dp[i - 1]
            if ratings[i] > ratings[i + 1]:
                right_val = dp[i + 1]
            dp[i] = 1 + max(left_val , right_val)
			
		#Check from front
        for i in range(1 , n):
            if ratings[i] > ratings[i - 1]:
                if dp[i] <= dp[i - 1]:
                    dp[i] = 1 + dp[i - 1]
					
		#Check from rear
        for i in range(n - 2 , -1 , - 1):
            if ratings[i] > ratings[i + 1]:
                if dp[i] <= dp[i + 1]:
                    dp[i] = 1 + dp[i + 1]
        return sum(dp)         