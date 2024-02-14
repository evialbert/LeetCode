class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        res= 0
        count= Counter(words[0])
        word_length= [len(words[0])]
        for word in words[1:]:
            count+= Counter(word)
            word_length.append(len(word))
        word_length.sort()
        palidrome= sum([x // 2 for x in count.values()])
        for i in word_length:
            if i==1:
                res+=1
            elif i//2<=palidrome:
                res+=1
                palidrome-=i//2
            else:
                break
        return res