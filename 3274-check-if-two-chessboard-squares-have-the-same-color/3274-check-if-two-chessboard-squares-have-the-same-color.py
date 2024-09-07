class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        return ((ord(coordinate1[0]) + int(coordinate1[1]))%2) == ((ord(coordinate2[0]) + int(coordinate2[1]))%2)