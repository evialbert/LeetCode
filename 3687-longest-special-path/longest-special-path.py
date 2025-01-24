class Solution:
    def longestSpecialPath(self, edges: List[List[int]], nums: List[int]) -> List[int]:
        G = defaultdict(list)
        for x, y, w in edges:
            G[x].append((y, w))
            G[y].append((x, w))

        cumPathLen, valToIdxPos = [], defaultdict(list)

        self.ans = 0
        self.minLen = 1

        def dfs(node, prevStart, parent):
            if valToIdxPos[nums[node]]:
                prevStart = max(prevStart, valToIdxPos[nums[node]][-1])
            if cumPathLen:
                L = cumPathLen[-1] if prevStart == -1 else cumPathLen[-1] - cumPathLen[prevStart]
                if L > self.ans:
                    self.ans = L
                    self.minLen = len(cumPathLen) + 1 - (prevStart + 1)
                elif L == self.ans:
                    self.minLen = min(self.minLen, len(cumPathLen) + 1 - (prevStart + 1))
            for child, length in G[node]:
                if child == parent:
                    continue
                valToIdxPos[nums[node]].append(len(cumPathLen))
                if cumPathLen:
                    cumPathLen.append(cumPathLen[-1] + length)
                else:
                    cumPathLen.append(length)
                dfs(child, prevStart, node)
                valToIdxPos[nums[node]].pop()
                cumPathLen.pop()

        dfs(0, -1, -1)
        return [self.ans, self.minLen]