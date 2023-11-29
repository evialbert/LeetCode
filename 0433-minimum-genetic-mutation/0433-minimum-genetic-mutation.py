class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        #@cache
        def dfs(s, count):
            #print(s)
            if s == endGene:
                ans.append(count)
                #print(ans)

            visited.append(s)
            for i in range(len(startGene)):
                for c in 'ACGT':
                    temp = s[:i]+c+s[i+1:]
                    if temp in bank and temp not in visited:
                        dfs(temp, count+1)
        visited = []
        ans = []
        dfs(startGene, 0)

        return -1 if ans == [] else ans[0]