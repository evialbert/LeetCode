class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        num_list = [row.count(1) for row in mat]
        num_dict = {i:num for i, num in enumerate(num_list)}
        return [key for (key,value) in sorted(num_dict.items(), key=lambda item: item[1])][:k]
            