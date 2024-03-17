class Solution:
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
        if not arr:
            return arr
        hashmap = dict()
        for i, word in enumerate(arr):
            for size in range(1, len(word)+1):
                for sli in range(len(word) - size + 1):
                    temp = word[sli:sli+size]
                    if i not in hashmap:
                        hashmap[i] = set()
                    hashmap[i].add(temp)
        rst = {k: list(v) for k, v in hashmap.items()}
        for i, d in enumerate(rst):
            for i_com in range(len(hashmap)):
                if i_com == i:
                    continue
                for v_com in hashmap[i_com]:
                    if v_com in rst[i]:
                        rst[i].remove(v_com)
        rst = {k: [(len(s), s) for s in v] for k, v in rst.items()}
        rst = [sorted(s)[0][1] if len(s) > 0 else '' for s in rst.values()]
        return rst