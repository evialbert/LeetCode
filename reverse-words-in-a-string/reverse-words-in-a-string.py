class Solution:

    # @param s, a string
    # @return a string
    def reverseWords(self, s):

        len_s = len(s)
        if len_s < 1:
            return s

        index_right = len_s - 1
        new_s = ""

        while index_right >= 0:
            while index_right >= 0 and ' ' == s[index_right]:
                index_right -= 1
            end_index = index_right
            while index_right >= 0 and ' ' != s[index_right]:
                index_right -= 1
            start_index = index_right + 1
            word = s[start_index : end_index + 1] if end_index >= 0 else ""
            new_s += (word + " ")

        return new_s.rstrip()