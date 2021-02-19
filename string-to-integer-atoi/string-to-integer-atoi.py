class Solution:
    def myAtoi(self, string:str) -> int:
        number = ""
        for char in string:
            try:
                number += str(int(char))
            except:
                if char == " ":
                    if len(number) == 0:
                        continue
                    else:
                        break
                elif (char == "+" or char == "-") and number == "":
                    number += char
                else:
                    if number == "":
                        return 0
                    else:
                        break
        try:
            number = int(number)
        except:
            number = 0
        if number >= 2**31 -1:
            number = 2**31 -1
        elif number <= - 2**31:
            number = - 2**31

        return number