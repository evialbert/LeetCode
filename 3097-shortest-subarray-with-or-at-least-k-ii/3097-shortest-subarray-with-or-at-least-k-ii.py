class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 1
        
        def window_to_decimal(arr):
            return  sum(2**i for i in range(32) if arr[i])
        
        def update_window(arr,num,delete):
            num = bin(num)[2:][::-1]
            for i in range(len(num)):
                arr[i]+= int(num[i])*delete
        
        window = [0]*32
        l = 0
        res = float('inf')

        for r,num in enumerate(nums):
            update_window(window,num,1)
            while window_to_decimal(window) >= k:
                res = min(res,r-l+1)
                update_window(window,nums[l],-1)
                l+=1
        
        return res if res!=float('inf') else -1
             
