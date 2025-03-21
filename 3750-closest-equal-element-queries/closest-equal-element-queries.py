class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        
        def binary_search(all_index , index):

            start , end = 0 , len(all_index)

            while start < end:

                mid = (start + end) // 2

                if all_index[mid] == index:
                    return mid
                if all_index[mid] < index:
                    start = mid + 1

                if all_index[mid] > index:
                    end = mid - 1
            
            return start

        result = []
        
        hashmap = defaultdict(list)
        
        for index in range(len(nums)):
            
            hashmap[nums[index]].append(index)
        
        for index in queries:
            
            all_index = hashmap[nums[index]]

            if len(all_index) == 1:
                result.append(-1)
            else:

                current_index = binary_search(all_index , index)

                min_distance = float('inf')

                if 0 < current_index < len(all_index) - 1:

                    min_distance = min(min_distance , abs(all_index[current_index + 1] - index))

                    min_distance = min(min_distance , abs(index - all_index[current_index - 1]))
                else:
                    if current_index == 0:

                        min_distance = min(min_distance , abs(all_index[current_index + 1] - index))

                        min_distance = min(min_distance , abs(index + len(nums) - all_index[-1]))
                        
                    if current_index == len(all_index) - 1:
                        
                        min_distance = min(min_distance , abs(all_index[0] + len(nums) - all_index[-1]))
                        
                        min_distance = min(min_distance , abs(index - all_index[current_index - 1] ))

                result.append(min_distance)
        
        return result