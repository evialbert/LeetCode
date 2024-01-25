class Solution:
    def minimumPushes(self, word: str) -> int:
        ans = 0
        count = Counter(word)
        maxFreq = max(count.values())
        freq = defaultdict(list)
        seen = {}
        
        for key,val in count.items():
            freq[val].append(key)
            
        k = 8
            
        while maxFreq>0:
            for val in freq[maxFreq]:
                if val not in seen:
                    seen[val]=k//8
                ans+=seen[val]*maxFreq
                k+=1
                
            maxFreq-=1
            
            
        return ans