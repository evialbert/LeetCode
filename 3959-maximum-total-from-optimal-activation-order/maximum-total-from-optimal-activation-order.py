class Solution:
    def maxTotal(self, value: List[int], limit: List[int]) -> int:
        result = 0
        data = defaultdict(list)
        for i in range(len(value)):data[limit[i]].append(value[i])
        for x in data:result += sum(sorted(data[x])[::-1][:x])
        return result