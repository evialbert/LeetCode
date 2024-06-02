class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        first = 0 
        second = len(s) - 1
        while first <= second: 
            #swap elements 
            s[first], s[second] = s[second], s[first]
            #increment/decrement counters
            first += 1 
            second -= 1
        return s 