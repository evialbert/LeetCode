class Solution:
    def constructGridLayout(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # get matrix shape
        m=len(edges)
        for r in range(1,int(sqrt(n))+1):
            if n%r==0:
                c=n//r
                if r+c == 2*n-m:
                    break

        # build output buffer
        self.row = r
        self.col = c

        # build connection graph
        self.graph = {i:[] for i in range(n)}
        for a,b in edges:
            self.graph[a].append(b)
            self.graph[b].append(a)
        
        try:
            # start assemble from top left
            self.buffer = [[-1]*self.col for _ in range(self.row)]
            stack = [(0,0)]
            self.used_numbers = set()
            while stack:
                if not stack:
                    break
                next_stack = []
                for x,y in stack:
                    # fill in x, y
                    next_nodes = self.query(x,y)
                    next_stack += next_nodes

                stack = next_stack
        except:
            self.col,self.row = r,c
            self.buffer = [[-1]*self.col for _ in range(self.row)]
            stack = [(0,0)]
            self.used_numbers = set()
            while stack:
                if not stack:
                    break
                next_stack = []
                for x,y in stack:
                    # fill in x, y
                    next_nodes = self.query(x,y)
                    next_stack += next_nodes

                stack = next_stack

        return self.buffer


    def query(self,x,y):
        # fill in node at (x,y) and return next nodes

        # if invalid
        if not self.check_valid(x,y):
            return []
       
        # if visited
        if self.buffer[x][y] != -1:
            return []

        edge_count, exist_neighbors = self.count_edge(x,y)
        val = self.solve_node(edge_count,exist_neighbors)
        self.buffer[x][y] = val

        return [(x,y+1),(x+1,y)]

    def check_valid(self,x,y):
        if x<0 or y<0 or x>=self.row or y>=self.col:
            return 0
        return 1

    def count_edge(self,x,y):
        edge_count=0
        exist_neighbors=[]
        for dx,dy in [[-1,0],[1,0],[0,1],[0,-1]]:
            node_valid=self.check_valid(x+dx,y+dy)
            if node_valid:
                edge_count+=1
                if self.buffer[x+dx][y+dy] != -1:
                    exist_neighbors.append(self.buffer[x+dx][y+dy])

        return edge_count,exist_neighbors

    def solve_node(self,edge_count,exist_neighbors):
        if not exist_neighbors:
            # pick any value with same edge count
            for val in self.graph:
                if len(self.graph[val])==edge_count and val not in self.used_numbers:
                    self.used_numbers.add(val)
                    return val
        
        cdd_set=None
        for neighbor in exist_neighbors:
            if not cdd_set:
                cdd_set = set(self.graph[neighbor])
            else:
                cdd_set = cdd_set & set(self.graph[neighbor])
        for cdd in cdd_set:
            if cdd not in self.used_numbers and len(self.graph[cdd])==edge_count:
                self.used_numbers.add(cdd)
                return cdd