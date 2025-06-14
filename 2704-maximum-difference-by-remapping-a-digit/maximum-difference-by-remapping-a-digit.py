class Solution:
    def minMaxDifference(self, num: int) -> int:
        num_str = str(num)
        
        max_num = num
        for d in set(num_str): 
            candidate_max = int(num_str.replace(d, '9'))
            max_num = max(max_num, candidate_max)

        min_num = num
        for d in set(num_str):
            candidate_min = int(num_str.replace(d, '0'))
            min_num = min(min_num, candidate_min)

        return max_num - min_num