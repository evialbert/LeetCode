class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        x = 1
        i = n
        while(i>1):
            x = 1+2*x
            i-=1
        inv = 0
        k-=1
        while(x>1):
            mid=x//2
            print(x,mid,inv,k)
            if k==mid:
                return "1" if inv%2!=1 else "0"
            if k>mid:
                k=2*mid-k
                inv+=1
            x = mid
        return "1" if inv%2!=0 else "0"
