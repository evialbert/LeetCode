class Node:
    def __init__(self,char):
        self.char=char
        self.children=[None]*26
class Trie:
    def __init__(self):
        self.root=Node('*')
    def insert(self,word):
        current=self.root
        for w in word:
            ascii_index=ord(w)-ord('a')
            if current.children[ascii_index]:
                current=current.children[ascii_index]
            else:
                n=Node(ascii_index)
                current.children[ascii_index]=n
                current=n

class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        t=Trie()
        for w in words:
            t.insert(w)
        @cache
        def dfs(i):
            if i>=len(target):
                return 0
            curr=t.root
            res=float('inf')
            for j in range(i,len(target)):
                idx=ord(target[j])-ord('a')
                if not curr.children[idx]:
                    break
                curr=curr.children[idx]
                res=min(res,1+dfs(j+1))
            return res
        return dfs(0) if dfs(0)!=float('inf') else -1
        