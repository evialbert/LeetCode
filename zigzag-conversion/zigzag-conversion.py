class Solution:
    # @return a string
    def convert(self, s, nRows):
        if 1 == nRows:
            return s

        len_s = len(s)
        piece_len = 2 * (nRows - 1)

        result = ""
        index = 0
        while index < len_s:
            result += s[index]
            index += piece_len
        for m in range(1, nRows - 1):
            index = m
            while index < len_s:
                result += s[index]
                right_index = index + (nRows - m - 1) * 2
                if right_index < len_s:
                    result += s[right_index]
                index += piece_len
        index = nRows - 1
        while index < len_s:
            result += s[index]
            index += piece_len

        return result