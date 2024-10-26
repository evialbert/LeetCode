class Solution:
    def finddiv(self, num):
        div = []
        for i in range(1, num):
            if num % i == 0:
                div.append(i)
        return div

    def minAnagramLength(self, s: str) -> int:
        divs = self.finddiv(len(s))

        for i in divs:
            ptr = 0
            prev = ""

            while ptr < len(s):
                temp = s[ptr:ptr+i]
                temp = ''.join(sorted(temp))

                if prev != temp and prev != "":
                    break

                prev = temp
                ptr += i
        
            if ptr == len(s):
                return i
        
        return len(s)