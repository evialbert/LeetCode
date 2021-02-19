class Solution:
    # @param {string[]} words
    # @param {integer} maxWidth
    # @return {string[]}
    def fullJustify(self, words, maxWidth):
        ret = []
        start = end = 0
        totallen = 0;
        while end < len(words):
            if totallen + len(words[end]) + end - start > maxWidth:
                space = (maxWidth - totallen) if (end == start + 1) else (maxWidth - totallen) / (end - 1 - start)
                extra = 0 if (end == start + 1) else (maxWidth - totallen) % (end - 1 - start)
                tmp = []
                if end == start + 1:
                    tmp.append(words[start])
                    tmp.append(' ' * space)
                else:
                    for i in range(start, end):
                        tmp.append(words[i])
                        if i == end - 1:
                            continue
                        tmp.append(' ' * space)
                        if extra:
                            tmp.append(' ')
                            extra -= 1
                ret.append(''.join(tmp))
                start = end
                totallen = 0
            else:
                totallen += len(words[end])
                end += 1
        tmp = []
        padding = maxWidth - totallen
        for i in range(start, end):
            tmp.append(words[i])
            if i == end - 1:
                tmp.append(' ' * padding)
            else:
                tmp.append(' ')
                padding -= 1
        ret.append(''.join(tmp))
        return ret