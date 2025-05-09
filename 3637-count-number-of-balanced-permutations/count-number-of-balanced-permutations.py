class Solution:
    def countBalancedPermutations(self, num: str) -> int:        
        sum_ = sum(int(char) for char in num)
        if sum_ % 2 == 1:
            return 0

        modulo = 10 ** 9 + 7
        data = sorted(Counter(int(char) for char in num).items())

        @cache
        def c_n_k(n, k):
            if n == k or k == 0:
                return 1
            return c_n_k(n - 1, k - 1) + c_n_k(n - 1, k)

        @cache
        def dp(index, left_cnt, right_cnt, left_sum, right_sum):
            if index == -1:
                if left_cnt == 0 and right_cnt == 0 and left_sum == right_sum:
                    return 1
                return 0
            
            if left_cnt < 0 or right_cnt < 0 or left_sum < 0 or right_sum < 0:
                return 0
            
            elem, cnt = data[index]
            result = 0
            for current_left_cnt in range(cnt + 1):
                if current_left_cnt > left_cnt:
                    break
                current_right_cnt = cnt - current_left_cnt
                if current_right_cnt > right_cnt:
                    continue
                current = (
                    c_n_k(left_cnt, current_left_cnt)
                    * c_n_k(right_cnt, current_right_cnt)
                    * dp(
                        index - 1,
                        left_cnt - current_left_cnt,
                        right_cnt - current_right_cnt,
                        left_sum - elem * current_left_cnt,
                        right_sum - elem * current_right_cnt
                    )
                )
                result = (result + current) % modulo
            return result
        
        n = len(num)
        return dp(
            index=len(data) - 1,
            left_cnt=(n + 1) // 2,
            right_cnt=n // 2,
            left_sum=sum_ // 2,
            right_sum=sum_ // 2,
        )