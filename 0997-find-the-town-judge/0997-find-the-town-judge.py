class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if trust == [] and n == 1:
            return 1 
            
        judge_options = []
        # Figuring the judge_options
        for people in trust:
            if people[1] not in judge_options:
                judge_options.append(people[1])

        for option in judge_options:
            count_trusties = 0
            
            for i in trust:
                # Because judge trust noone
                # so break if the judge_options trust someone 
                if i[0] == option:
                    count_trusties = 0 
                    break

                if i[1] == option:
                    count_trusties += 1
            # Always n-1 people will trust the judge.   
            if count_trusties == n-1:
                 return option

        return -1