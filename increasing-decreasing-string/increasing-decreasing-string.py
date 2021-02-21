class Solution:
    def sortString(self, s: str) -> str:
        answer = ''
        hashset = {}
        # get character count of the string
        for i in s:
            if hashset.get(i) == None:
                hashset[i] = 1
            else:
                hashset[i] += 1
        # build the answer string by iterating from 'a' to 'z' or vice versa
        while len(answer) < len(s):
            for i in range(ord('a'),ord('z')+1):
                if hashset.get(chr(i)) != None:
                    if hashset.get(chr(i)) > 0:
                        hashset[chr(i)] -= 1
                        answer += chr(i)
            for i in range(ord('z'), ord('a')-1, -1):
                if hashset.get(chr(i)) != None:
                    if hashset.get(chr(i)) > 0:
                        hashset[chr(i)] -= 1
                        answer += chr(i)
        return answer