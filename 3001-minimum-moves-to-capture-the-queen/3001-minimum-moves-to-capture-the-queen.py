class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        if a==e:
            if c==a:
                if d>b and d>f:
                    return 1
                elif d<b and d<f:
                    return 1
            else:
                return 1
        elif b==f:
            if d==b:
                if c>a and c>e:
                    return 1
                elif c<a and c<e:
                    return 1
            else:
                return 1
                
        elif abs(c-e) == abs(d-f):
            if c<e:
                s = c
                t = e 
                if d>f:
                    count = d
                    for i in range(s,t):
                        if i==a:
                            if b==count:
                                return 2
                        count-=1
                    return 1
                else:
                    count = d
                    for i in range(s,t):
                        if i==a:
                            if b==count:
                                return 2
                        count+=1 
                    return 1
            else:
                s = e
                t = c
                if f>d:
                    count = f
                    for i in range(s,t):
                        if i==a:
                            if b==count:
                                return 2
                        count-=1
                    return 1
                else:
                    count = f
                    for i in range(s,t):
                        if i==a:
                            if b==count:
                                return 2
                        count+=1
                    return 1
            return 1
        return 2
        
        