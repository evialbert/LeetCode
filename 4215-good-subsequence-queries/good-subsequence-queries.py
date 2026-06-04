class Solution:
    def countGoodSubseq(self, nums: list[int], p: int, queries: list[list[int]]) -> int:

        self.arr = nums
        self.P = p
        self.n = len(nums)

        self.seg = [0]*(4*self.n)

        def gcdv(a,b):
            if a==0: return b
            if b==0: return a
            while b:
                a,b = b, a%b
            return a

        def build(i,l,r):
            if l==r:
                self.seg[i] = self.arr[l]//self.P if self.arr[l]%self.P==0 else 0
                return

            m = (l+r)//2

            build(i*2,l,m)
            build(i*2+1,m+1,r)

            self.seg[i] = gcdv(self.seg[i*2], self.seg[i*2+1])

        def update(i,l,r,idx,val):
            if l==r:
                self.seg[i] = val//self.P if val%self.P==0 else 0
                return

            m = (l+r)//2

            if idx<=m:
                update(i*2,l,m,idx,val)
            else:
                update(i*2+1,m+1,r,idx,val)

            self.seg[i] = gcdv(self.seg[i*2], self.seg[i*2+1])

        def canExcludeOne(i,l,r,ext):
            if l==r:
                return ext==1

            m = (l+r)//2

            left  = gcdv(ext, self.seg[i*2+1])
            right = gcdv(ext, self.seg[i*2])

            if left==1 or right==1:
                return True

            return (canExcludeOne(i*2,l,m,left) or
                    canExcludeOne(i*2+1,m+1,r,right))

        cnt = sum(1 for x in self.arr if x%self.P==0)

        build(1,0,self.n-1)

        ans = 0

        for idx,val in queries:

            if self.arr[idx] % self.P == 0:
                cnt -= 1
            if val % self.P == 0:
                cnt += 1

            self.arr[idx] = val

            update(1,0,self.n-1,idx,val)

            if self.seg[1] == 1:
                if cnt < self.n:
                    ans += 1
                elif canExcludeOne(1,0,self.n-1,0):
                    ans += 1

        return ans