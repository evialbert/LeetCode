class Solution:
    def minimumLength(self, s: str) -> int:
        count = [0]*26
        for ch in s:
            count[ord(ch)-ord('a')] += 1
        ans = 0
        for i in count:
            if i == 0:
                continue
            if  i % 2 == 0:
                print(i)
                ans += 2
            else:
                ans += 1
        print(count)
        return ans  