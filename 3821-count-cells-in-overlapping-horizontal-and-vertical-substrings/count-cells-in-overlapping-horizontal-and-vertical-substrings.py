class Solution:
    def countCells(self, grid: List[List[str]], pattern: str) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0
        h_score = [0]*(m*n+1)
        v_score = [0]*(m*n+1)
        v_final = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]
        h_final = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]
        def compute_lps(pattern):
            m = len(pattern)
            lps = [0] * m
            length = 0
            i = 1
            while i < m:
                if pattern[i] == pattern[length]:
                    length += 1
                    lps[i] = length
                    i += 1
                else:
                    if length != 0:
                        length = lps[length-1]
                    else:
                        lps[i] = 0
                        i += 1
            return lps
        def kmp_search(s, pattern):
            n, m = len(s), len(pattern)
            lps = compute_lps(pattern)
            indices = []
            i = 0
            j = 0
            while i < n:
                if s[i] == pattern[j]:
                    i += 1
                    j += 1
                if j == m:
                    indices.append(i - j)
                    j = lps[j-1]
                elif i < n and s[i] != pattern[j]:
                    if j != 0:
                        j = lps[j-1]
                    else:
                        i += 1
            return indices
        h = ""
        v = ""
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                h += grid[i][j]
        for j in range(len(grid[0])):
            for i in range(len(grid)):
                v += grid[i][j]
        h_output = kmp_search(h,pattern)
        v_output = kmp_search(v,pattern)
        v_prefixsum = []
        h_prefixsum = []

        for x in h_output:
            h_score[x] += 1
            h_score[x+len(pattern)] -= 1
        for x in v_output:
            v_score[x] += 1
            v_score[x+len(pattern)] -= 1
        
        v_prefixsum = [v_score[0]]*len(v_score)
        
        h_prefixsum = [h_score[0]]*len(h_score)
        
        for i in range(len(v_score)):
            if i == 0:
                v_final[0][0] = v_score[0]
                continue
            if i >= m*n:
                continue
            v_prefixsum[i] = v_prefixsum[i-1]+v_score[i]
            # print(i//m,i%m)
            v_final[i%m][i//m]= v_prefixsum[i]
        for i in range(len(h_score)):
            if i == 0:
                h_final[0][0] = h_score[0]
                if v_final[0][0] >0 and h_final[0][0] >0:
                    ans += 1
                continue
            if i >= m*n:
                continue
            h_prefixsum[i] = h_prefixsum[i-1]+h_score[i]
            h_final[i//n][i%n]= h_prefixsum[i]
            if v_final[i//n][i%n] >0 and h_final[i//n][i%n] >0:
                ans += 1 
        
        # print(h_final)
        # print(v_final)
        return ans