class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        s = []
        for i in range(len(nums)):
            if nums[i][i] == '1':
                s.append('0');
            elif nums[i][i] == '0':
                s.append('1');

        return "".join(s)