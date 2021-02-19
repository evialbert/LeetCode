public class Solution {
    private class Cell
    {
        public int Column;
        public int Row;
        public int Box;
        public char Value;
        public List<Cell> Others;
        public bool[] PossibleDigits;
    }

    public void SolveSudoku(char[][] board) {
        var cells = GetCells(board);
        var emptyCells = cells.Where(c => c.Value == '.').ToList();
        foreach (var cell in emptyCells)
        {
            cell.Others = cells.Where(c => (c.Column == cell.Column || c.Row == cell.Row || c.Box == cell.Box) && c != cell).ToList();
            cell.PossibleDigits = new bool[9];
        }
        Solve(0,emptyCells);
        foreach (var cell in cells)
        {
            board[cell.Row][cell.Column] = cell.Value;
        }
    }
     
    private static bool Solve(int index,List<Cell> emptyCells)
    {
        if (index >= emptyCells.Count)
        {
            return true;
        }
        var cell = emptyCells[index];
        for (var i = 0; i < 9; i++)
        {
            cell.PossibleDigits[i] = true;
        }
        foreach (var other in cell.Others)
        {
            if (other.Value != '.')
            {
                cell.PossibleDigits[other.Value-'1'] = false;
            }
        }
        for (var i = 0; i < 9; i++)
        {
            if (!cell.PossibleDigits[i])
            {
                continue;
            }
            cell.Value = (char)('1' + i);
            if (Solve(index+1,emptyCells))
            {
                return true;
            }
        }
        cell.Value = '.';
        return false;
    }
    
    private static List<Cell> GetCells(char[][] board)
    {
        var cells = new List<Cell>();
        for (var c = 0; c < 9; c++)
        {
            for (var r = 0; r < 9; r++)
            {
                cells.Add(new Cell
                {
                    Column = c,
                    Row = r,
                    Box = r/3*3 + c/3,
                    Value = board[r][c]
                });
            }
        }
        return cells;
    }
}
