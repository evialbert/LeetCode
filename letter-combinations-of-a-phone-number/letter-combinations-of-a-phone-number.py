class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        map_ = {
            "2": 'abc',
            "3": 'def',
            "4": 'ghi',
            "5": 'jkl',
            "6": 'mno',
            "7": 'pqrs',
            "8": 'tuv',
            "9": 'wxyz'
        }
        ret = []
        def dfs(path, digits):
            if not digits:
            	# end condition is not more digits
                return ret.append(path)
            for d in map_[digits[0]]:
                dfs(path + d, digits[1:])
        if digits:  # make sure empty list is returned
            dfs("", digits)
        return ret