class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_ = sorted(copy.deepcopy(set(arr)))
        arr_d = dict(zip(arr_, list(range(1, len(arr_)+1))))
        return [arr_d[a] for a in arr]        