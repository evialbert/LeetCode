class Solution:
   def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
    seen = [False] * 26
    dist = [ [inf] * 26 for _ in range(26)]
    for x in range(ord('z')-ord('a')+1):
        dist[x][x] = 0
    for s, t, c in zip(original, changed, cost):
        s = ord(s)-ord('a')
        t = ord(t)-ord('a')
        seen[s] = seen[t] = True
        dist[s][t] = min(dist[s][t], c)
    seen2 = tuple([i for i, x in enumerate(seen) if x])
    for k in seen2:
        for a in seen2:
            for b in seen2:
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b])
    
    ret = sum(dist[ord(s)-ord('a')][ord(t)-ord('a')] for s, t in zip(source, target))
    return ret if ret != inf else -1     