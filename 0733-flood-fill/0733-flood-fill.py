class Solution:
    # O(n) time | O(n) space
    def floodFill(self, image: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        self.dfs(image, row, col, color, image[row][col])
        return image
        

    def dfs(self, image: List[List[int]], row: int, col: int, color: int, pixel: int):
        if row < 0 or row == len(image) or col < 0 or col == len(image[0]):
            return

        if image[row][col] != pixel or image[row][col] == color:
            return

        image[row][col] = color

        self.dfs(image, row + 1, col, color, pixel)
        self.dfs(image, row - 1, col, color, pixel)
        self.dfs(image, row, col + 1, color, pixel)
        self.dfs(image, row, col - 1, color, pixel)