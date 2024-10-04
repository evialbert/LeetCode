class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        total_skill = sum(skill) / (len(skill)/2)
        left , right = 0 , len(skill)-1
        res = 0
        while left < len(skill) / 2 :
            target_skill = skill[left] + skill[right]
            if target_skill != total_skill:
                return -1
            res += skill[left] * skill[right]
            left , right = left + 1, right - 1
        return res