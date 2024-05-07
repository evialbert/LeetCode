class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        mapper = {}
        n = len(word)
        i=0
        while i+k<n+1:
            curr = word[i:i+k]
            if curr not in mapper:
                mapper[curr]=0
            mapper[curr]+=1
            i=i+k
        
        print(mapper)
        maxval = 0
        for key,val in mapper.items():
            if val > maxval:
                maxval = val
        
        return int(n/k - maxval)