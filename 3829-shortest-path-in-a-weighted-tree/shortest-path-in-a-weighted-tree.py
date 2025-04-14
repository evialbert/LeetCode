class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [0] * (4 * self.n)
        self.data = data[:]
        self.build(0, 0, self.n - 1)

    def build(self, node, start, end):
        if start == end:
            self.tree[node] = self.data[start]
        else:
            mid = (start + end) // 2
            self.build(2 * node + 1, start, mid)
            self.build(2 * node + 2, mid + 1, end)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]

    def update(self, idx, value):
        self.data[idx] = value
        self._update(0, 0, self.n - 1, idx, value)

    def _update(self, node, start, end, idx, value):
        if start == end:
            self.tree[node] = value
        else:
            mid = (start + end) // 2
            if start <= idx <= mid:
                self._update(2 * node + 1, start, mid, idx, value)
            else:
                self._update(2 * node + 2, mid + 1, end, idx, value)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]

    def query(self, left, right):
        return self._query(0, 0, self.n - 1, left, right)

    def _query(self, node, start, end, left, right):
        if right < start or left > end:
            return 0
        if left <= start and end <= right:
            return self.tree[node]
        mid = (start + end) // 2
        sum_left = self._query(2 * node + 1, start, mid, left, right)
        sum_right = self._query(2 * node + 2, mid + 1, end, left, right)
        return sum_left + sum_right
class Solution:
    def treeQueries(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        
        
        
        
        arr = [ ]
        
        
        graph = defaultdict(list)
        weight = defaultdict(int)
        
        for x,y,w in edges:
            graph[x].append(y)
            graph[y].append(x)
            weight[(x,y)] = w
            weight[(y,x)] = x
        
        index = defaultdict(int)
        neg = defaultdict(int)
        previous = defaultdict(int)
        def dfs(node,prev):
            
            arr.append(weight[(prev,node)])
            index[(prev,node)]=len(arr)-1
            previous[node] = prev
            
            
            if len(graph[node])==0:
                arr.append(-weight[(prev,node)])
                neg[(prev,node)]=len(arr)-1
            else:

                for x in graph[node]:
                    if x==prev:
                        continue
                    dfs(x,node)
                arr.append(-weight[(prev,node)])
                neg[(prev,node)] = len(arr)-1
            
        dfs(1,-1)
        
        ans = []
        obj = SegmentTree(arr)
        
        for x in queries:

            if len(x)==2:
                ans.append(obj.query(index[(-1,1)],index[(previous[x[1]],x[1])]))
            else:
                
                if previous[x[2]]==x[1]:
                    obj.update(index[(x[1],x[2])],x[3])
                    obj.update(neg[(x[1],x[2])],-x[3])
                else:
                    obj.update(index[(x[2],x[1])],x[3])
                    obj.update(neg[(x[2],x[1])],-x[3])
                    
                    
        return ans
                        
        