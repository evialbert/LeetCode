class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        cache = collections.defaultdict(list)
        
        if len(nums) < 4:
            return []
        
        answer = set()
        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                s = nums[i] + nums[j]
                miss = target - s
                if miss in cache:
                    for elem in cache[miss]:
                        if i not in elem and j not in elem:
                            ans = [nums[i], nums[j], nums[elem[0]], nums[elem[1]]]
                            ans.sort()
                            answer.add(tuple(ans))
                
                cache[s].append((i, j))
        
        return answer