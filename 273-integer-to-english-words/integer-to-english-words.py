class Solution:
    def numberToWords(self, num: int) -> str:

        mapping = {
        0: "Zero",
        1: "One",
        2: "Two",
        3: "Three",
        4: "Four",
        5: "Five",
        6: "Six",
        7: "Seven",
        8: "Eight",
        9: "Nine",
        10: "Ten",
        11: "Eleven",
        12: "Twelve",
        13: "Thirteen",
        14: "Fourteen",
        15: "Fifteen",
        16: "Sixteen",
        17: "Seventeen",
        18: "Eighteen",
        19: "Nineteen",
        20: "Twenty",
        30: "Thirty",
        40: "Forty",
        50: "Fifty",
        60: "Sixty",
        70: "Seventy",
        80: "Eighty",
        90: "Ninety",
        100: "Hundred",
        1000: "Thousand",
        1000000: "Million",
        1000000000: "Billion"
        }

        def chunkwhole(string):
            chunks = []
            for i in range(0, len(string) - 2, 3):
                chunks.append(string[i:i+3])
            return chunks

        def chunkstring(string):
            chunks = []
            if len(string) % 3 == 1:
                chunks.append(string[0])
                chunks += chunkwhole(string[1:])
            elif len(string) % 3 == 2:
                chunks.append(string[0:2])
                chunks += chunkwhole(string[2:])
            else:
                chunks += chunkwhole(string)
            return chunks
        
        def processChunk(chunk):
            n = len(chunk)
            
            if n == 1:
                return mapping[int(chunk[0])]
            elif n == 2:
                if chunk[0] == chunk[1] == '0':
                    return ""
                if chunk[0] == '0':
                    return processChunk(chunk[1:])
                if chunk[0] == '1': # 10 - 19
                    return mapping[int(chunk)]
                else:
                    tenth = int(chunk) // 10 * 10
                    if chunk[1] != '0':
                        return mapping[tenth] + ' ' + mapping[int(chunk[1])]
                    else:
                        return mapping[tenth]
            else: # n = 3
                if chunk[0] == chunk[1] == chunk[2] == '0':
                    return ""
                if chunk[0] == chunk[1] == '0':
                    return processChunk(chunk[2])
                if chunk[0] == '0' and chunk[1] != '0':
                    return processChunk(chunk[1:])
                hundred = mapping[int(chunk[0])] + ' Hundred '
                return hundred + processChunk(chunk[1:])
    
                
        num = str(num)
        chunks = chunkstring(num)
        ans = []
        # print(chunks)
        for i, c in enumerate(chunks):
            ans.append(processChunk(c))
        # print(ans)
        
        answer = []
        nchunks = len(chunks)
        start = 0
        def getUnit(n):
            if n == 2:
                return ['Thousand']
            elif n == 3:
                return ['Million','Thousand']
            elif n == 4:
                return ['Billion','Million','Thousand']
            else:
                return [""]
        units = getUnit(nchunks)
        for a in ans:
            # print(answer)
            if a != '':
                answer += [a]
            if start < len(units):
                if answer[-1].strip() in ['Billion','Million','Thousand']:
                    start += 1
                    continue
                answer += [units[start]]
            start += 1
        return ' '.join(map(lambda x: x.strip(), answer)).strip()