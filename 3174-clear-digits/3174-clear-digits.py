class Solution:
    def clearDigits(self, s: str) -> str:
        result = []

        for character in s:
            if character.isalpha():
                result.append(character)
            elif character.isdigit() and result:
                result.pop()

        return ''.join(result)