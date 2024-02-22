class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        
        prime_nums = defaultdict(int)
        m = len(mat)
        n = len(mat[0])
        @lru_cache
        def isPrime(num):
            
            for i in range(2,(num//2)+1):
                if num % i == 0:
                    return False
            return True
        def count(i,j):
            #left
            num = mat[i][j]
            cur = num
            for col in range(j+1,n):
                cur*= 10
                cur += mat[i][col]
                if isPrime(cur):
                    prime_nums[cur] += 1
            #right
            cur =num
            if j-1 >= 0:
                for col in range(j-1,-1,-1):
                    cur *= 10
                    cur += mat[i][col]
                    if isPrime(cur):
                        prime_nums[cur] += 1
            #up
            cur = num
            if i-1 >=0:
                for row in range(i-1,-1,-1):
                    cur *= 10
                    cur += mat[row][j]
                    if isPrime(cur):
                        prime_nums[cur] += 1
            #Down
            cur = num
            if i+1 < m:
                for row in range(i+1,m):
                    cur *= 10
                    cur += mat[row][j]
                    if isPrime(cur):
                        prime_nums[cur] += 1
            
            row = i+1
            col = j+1
            cur = num
            while row < m and col < n:
                cur *= 10
                cur += mat[row][col]
                if isPrime(cur):
                    prime_nums[cur] += 1
                row += 1
                col += 1
            
            row = i - 1
            col = j-1
            cur = num
            while row >=0 and col>=0:
                cur *= 10
                cur += mat[row][col]
                if isPrime(cur):
                    prime_nums[cur] += 1
                row -= 1
                col -= 1
            row = i+1
            col = j- 1
            cur = num
            while row<m and col>=0:
                cur *= 10
                cur += mat[row][col]
                if isPrime(cur):
                    prime_nums[cur] += 1
                row += 1
                col -= 1
            row = i - 1
            col = j + 1
            cur = num
            while row >= 0 and col < n:
                cur *= 10
                cur += mat[row][col]
                if isPrime(cur):
                    prime_nums[cur] += 1
                row -= 1
                col += 1
                       
        if m==1 and n==1:
            return -1
        for i in range(m):
            for j in range(n):
                count(i,j)
        ans = [(val,key) for key,val in prime_nums.items()]
        ans = sorted(ans,key=lambda x: (x[0],x[1]),reverse=True)
        print(ans)
        # return -1
        return ans[0][1] if prime_nums else -1
                