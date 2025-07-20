class Trie:
    def __init__(self):
        self.children = defaultdict(Trie)
        self.delete = False

    def add(self, word):
        curr = self
        for c in word:
            curr = curr.children[c]

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = Trie()
        for path in sorted(paths):
            root.add(path)
        def serialize(t):
            if not t.children:return ""
            s = []
            for folder, child in t.children.items():
                s.append(folder + '(' + serialize(child) +')')
            key = "".join(s)
            seen[key].append(t)
            return key

        seen = defaultdict(list)
        serialize(root)

        for nodes in seen.values():
            if len(nodes) >= 2:
                for node in nodes:node.delete= True
        def dfs(root, path):
            for folder, child in root.children.items():
                if not child.delete:
                    curr = path + [folder]
                    res.append(curr)
                    dfs(child, curr)
        res = []
        dfs(root, [])
        return res


        