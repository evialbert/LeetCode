class Solution:
    def maxFreqSum(self, s: str) -> int:
        vow_heap={"a":0}
        con_heap={"A":0}
        vowels=["a","e","i","o","u","A","E","I","O","U"]
        for i in s:
            if i in vowels:
                if i in vow_heap:
                    vow_heap[i]+=1
                else:
                    vow_heap[i]=1
            else:
                if i in con_heap:
                    con_heap[i]+=1
                else:
                    con_heap[i]=1
        return max(con_heap.values())+max(vow_heap.values())