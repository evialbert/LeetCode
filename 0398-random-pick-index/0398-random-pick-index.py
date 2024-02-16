class Solution:

    def __init__(self, nums: List[int]):
        self.hash_map = {}

        for index, item in enumerate(nums):
            if item not in self.hash_map:
                self.hash_map[item] = []
            self.hash_map[item].append(index)
        print(self.hash_map)
        self.total = len(nums)-1

    def pick(self, target: int) -> int:
        index_list = self.hash_map[target]
        random_num = random.randint(0, len(index_list)-1)

        return index_list[random_num]
    
# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)