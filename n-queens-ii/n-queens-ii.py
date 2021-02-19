class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def check(row,num):
            for i in range(row):
                if board[i]==num or abs(num-board[i])==abs(i-row):
                    return False 
            return True 
        board=[-1]*n         
        count=row=num=0
        while row<n:
            while num<n:
                if check(row,num):
                    board[row]=num 
                    num=0
                    break 
                else:
                    num+=1
            if board[row]==-1:#这行找不到有效放置方法，退回上一层
                if row==0: #退出循环
                    break
                row-=1
                num=board[row]+1
                board[row]=-1
                continue
            if row==n-1:
                count+=1
                num=board[row]+1
                board[row]=-1
                continue  
            row+=1
        return count