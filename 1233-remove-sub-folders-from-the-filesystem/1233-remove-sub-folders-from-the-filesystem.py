class Solution:
    def is_subset(self, node, parts):
        for idx in range(1, len(parts)):
            if parts[idx] not in node:
                node[parts[idx]] = {}
                
            if 'end' in node[parts[idx]]:
                return True
            
            node = node[parts[idx]]
        
        node['end'] = True
        
        return False
                
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = {}
        folder.sort()
        res = []
        
        for f in folder:
            parts = f.split('/')
            
            if not self.is_subset(trie, parts):
                res.append(f)
        
        return res  