class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        letter = [i.lower() for i in licensePlate if  'a'<= i <='z' or 'A'<= i <= 'Z']
        countle = collections.Counter(letter)
        sortwords = sorted(words,key = len)
        for x in sortwords:
            flag = 0
            countx = collections.Counter(x)
            for key,val in countle.items():
                if key not in countx.keys() or  val > countx[key]:
                    flag = 1
                    break
            if flag == 0:return x
            