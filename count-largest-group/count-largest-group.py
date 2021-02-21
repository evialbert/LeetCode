class Solution:
    def countLargestGroup(self, n: int) -> int:
        hashMap = {}
        
        for num in range(1, n+1):
            sum_num_digits = 0
            while(num > 0):
                dig = num%10
                sum_num_digits = sum_num_digits + dig
                num = num//10
            if sum_num_digits not in hashMap:
                hashMap[sum_num_digits] = 0
            hashMap[sum_num_digits] += 1
        
        max_value = 0
        solution = 0
        for key in hashMap:
            if hashMap[key] > max_value:
                max_value = hashMap[key]
                solution = 0
            if hashMap[key] == max_value:
                solution += 1
        return solution