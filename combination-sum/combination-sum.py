class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates: return []
        answer = []
        candidates.sort()
        n = len(candidates)
        
        def dfs(i, nums, target):
            if target == 0:  # We have found our answer
                answer.append(nums)
                return
            for j in range(i, n):
                if candidates[j] > target:  #  Because of sorting there is no need to look further.
                    return
                dfs(j, nums + [candidates[j]], target-candidates[j])
        
        for i in range(len(candidates)):
            dfs(i, [candidates[i]], target-candidates[i])
        return answer