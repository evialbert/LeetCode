class Solution:
    def frequencySort(self, s: str) -> str:

        counter = {char: s.count(char) for char in set(s)}
        
        string = "".join([char * counter[char] for char in dict(sorted(counter.items(),key=lambda x:x[1], reverse=True))])

        return string
