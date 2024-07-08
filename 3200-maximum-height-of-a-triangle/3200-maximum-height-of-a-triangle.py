class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def height(r,b,colour):
            row=1
            cc=colour
            while True:
                if cc=="red":
                    if r>=row:
                        r-=row
                    else:
                        break
                    cc="blue"
                else:
                    if b>=row:
                        b-=row
                    else:
                        break
                    cc="red"
                row+=1
            return row-1
        forblue=height(red,blue,"blue")
        forred=height(red,blue,"red")
        return max(forblue,forred)