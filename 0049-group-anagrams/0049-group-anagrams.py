class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups_d = defaultdict(list)
        for s in strs:
            groups_d[''.join(sorted(list(s)))].append(s)
        return list(groups_d.values())