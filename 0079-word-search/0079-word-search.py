class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def wordsearch(i,j,k):
            if k==len(word):
                return True
            if i<0 or j<0 or i>=len(board) or j>=len(board[0]) or word[k]!=board[i][j] or vis[i][j]:
                return False
            vis[i][j]=True
            left=wordsearch(i-1,j,k+1)
            right=wordsearch(i+1,j,k+1)
            up=wordsearch(i,j+1,k+1)
            down=wordsearch(i,j-1,k+1)
            vis[i][j]=False
            return up or down or left or right   


        vis=[[False]*len(board[0]) for _ in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==word[0]:
                    ans=wordsearch(i,j,0)
                    if ans==True:
                        return True
        return False                