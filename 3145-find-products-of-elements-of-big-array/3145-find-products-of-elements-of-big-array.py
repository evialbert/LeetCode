class Solution:
    def findProductsOfElements(self, queries: List[List[int]]) -> List[int]:
        
        def cnt1(num: int) -> int:
            res = 0
            for i in range(num.bit_length()):
                cur = num % (1<<i+1)
                res += (num-cur) // 2 
                if cur >= 1<<i:
                    res += cur+1 - (1<<i)
            return res
        
        def acc0(num: int) -> int:
            res = 0
            for i in range(num.bit_length()):
                cur = num % (1<<i+1)
                res += (num-cur) // 2 * i
                if cur >= 1<<i:
                    res += (cur+1 - (1<<i)) * i
            return res
        
        def count(bound: int) -> int:
            # target is the number in the big_nums before decomposition that bound locates in
            target = bisect_left(range(bound), bound, key=cnt1)

            rest = bound - cnt1(target-1)
            cnt = acc0(target-1)
            
            for i in range(target.bit_length()):
                if target & (1<<i):
                    cnt += i
                    rest -= 1
                    if not rest:    break

            return cnt
        
        return [pow(2,count(high+1)-count(low),mod) for low,high,mod in queries]