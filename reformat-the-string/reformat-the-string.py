class Solution:
    def reformat(self, s: str) -> str:
        num="".join(list(filter(str.isdigit,s)))
        char="".join(list(filter(str.isalpha,s)))
        if abs(len(num)-len(char))>1:
            res=""
        elif len(num)==len(char):
            res=""
            for i in range(len(num)):
                res+="".join(num[i]+char[i])
        elif len(num)-len(char)==1:
            res=num[-1]
            for i in range(len(char)):
                res+="".join(char[i]+num[i])
        else:
            res=char[-1]
            for i in range(len(num)):
                res+="".join(num[i]+char[i])
        return res