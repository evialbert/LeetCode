class Solution:
    def numMagicSquaresInside(self, G: List[List[int]]) -> int:
    	M, N, S, t, s = len(G), len(G[0]), set(range(1,10)), range(3), 0
    	for i in range(M-2):
    		for j in range(N-2):
    			g = [G[i+k][j:j+3] for k in t]
    			if set(sum(g,[])) != S or g[1][1] != 5: continue
    			if any(sum(g[k]) != 15 for k in t) or any(sum([g[k][l] for k in t]) != 15 for l in t): continue
    			if sum([g[k][k] for k in t]) != 15 or sum([g[k][2-k] for k in t]) != 15: continue
    			s += 1
    	return s