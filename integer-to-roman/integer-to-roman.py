class Solution:
    def intToRoman(self, num: int) -> str:
        rom_str = ''
        if num >= 1000:
            rep, num = divmod(num, 1000)
            rom_str += 'M' * rep

        for div, one_char, five_char, ten_char in [
                (100, 'C', 'D', 'M'),
                (10, 'X', 'L', 'C'),
                (1, 'I', 'V', 'X')]:

            if num >= div:
                rep, num = divmod(num, div)
                if rep == 0:
                    continue
                elif rep == 9:
                    rom_str += one_char + ten_char
                elif rep > 5:
                    rom_str += five_char + (one_char * (rep - 5))
                elif rep == 5:
                    rom_str += five_char
                elif rep == 4:
                    rom_str += one_char + five_char
                else:
                    rom_str += (one_char * rep)
        return rom_str