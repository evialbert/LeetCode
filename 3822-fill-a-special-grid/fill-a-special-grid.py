class Solution:
    def specialGrid(self, n: int) -> List[List[int]]:
        if n==0:
            return [[0]]
        
        def fun(a,l,r,r1,c1,r2,c2):
            if (l-r)<=4:
                #print(r1,c1,r2,c2)
                a[r1][c1]=l-1
                a[r2-1][c1]=l-2
                a[r2-1][c2-1]=l-3
                a[r1][c2-1]=l-4
                return 
            x=(l-r)//4
            a1=fun(a,l,l-x,r1,c1,r1+(r2-r1)//2,c1+(c2-c1)//2)
            cl=l-x
            cr=cl-x
            a2=fun(a,cl,cr,r1+(r2-r1)//2,c1,r2,c1+(c2-c1)//2)
            cl=cr
            cr=cl-x
            a3=fun(a,cl,cr,r1+(r2-r1)//2,c1+(c2-c1)//2,r2,c2)
            cl=cr
            cr=cl-x
            a4=fun(a,cl,cr,r1,c1+(c2-c1)//2,r1+(r2-r1)//2,c2)
            return


        x=2**n
        l=x*x
        a=[[0 for i in range(x)] for j in range(x)]
        fun(a,l,0,0,0,x,x)
        return a