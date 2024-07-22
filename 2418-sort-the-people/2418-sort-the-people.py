class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        res = []
        for i in range(len(names)) :
            res.append([names[i], heights[i]])
        return list(map(lambda x : x[0], sorted(res, key=lambda a : -a[1])))