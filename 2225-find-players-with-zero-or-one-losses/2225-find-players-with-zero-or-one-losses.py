class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        absolute = set()
        other = collections.defaultdict(int)
        
        for w, l in matches:
            if other[w] == 0:
                absolute.add(w)
            
            if l in absolute:
                absolute.remove(l)
            
            other[l] += 1
        
        return [sorted(list(absolute)), sorted([key for key in other if other[key] == 1])]