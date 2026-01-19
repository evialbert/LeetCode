public class Solution
{
    public int LargestMagicSquare(int[][] InputGrid)
    {
        int RowCount = InputGrid.Length;
        int ColumnCount = InputGrid[0].Length;

        for (int SideLength = Math.Min(RowCount, ColumnCount); SideLength > 1; SideLength--)
        {
            if (CheckIfSquareExists(InputGrid, RowCount, ColumnCount, SideLength))
            {
                return SideLength;
            }
        }

        return 1;
    }

    public bool CheckIfSquareExists(int[][] InputGrid, int RowCount, int ColumnCount, int SideLength)
    {
        int MaxRowIndex = RowCount - SideLength;
        int MaxColumnIndex = ColumnCount - SideLength;

        for (int RowIndex = 0; RowIndex <= MaxRowIndex; RowIndex++)
        {
            for (int ColumnIndex = 0; ColumnIndex <= MaxColumnIndex; ColumnIndex++)
            {
                if (IsValidMagicSquare(InputGrid, RowIndex, ColumnIndex, SideLength))
                {
                    return true;
                }
            }
        }

        return false;
    }

    public bool IsValidMagicSquare(int[][] InputGrid, int StartRow, int StartColumn, int SideLength)
    {
        HashSet<int> UniqueSums = new HashSet<int>();
        int[] RowSums = new int[SideLength];
        int[] ColumnSums = new int[SideLength];
        int MainDiagonalSum = 0;
        int AntiDiagonalSum = 0;

        for (int RowOffset = 0; RowOffset < SideLength; RowOffset++)
        {
            for (int ColOffset = 0; ColOffset < SideLength; ColOffset++)
            {
                int CurrentValue = InputGrid[StartRow + RowOffset][StartColumn + ColOffset];
                
                RowSums[RowOffset] += CurrentValue;
                ColumnSums[ColOffset] += CurrentValue;

                if (RowOffset == ColOffset)
                {
                    MainDiagonalSum += CurrentValue;
                }
                
                if (RowOffset + ColOffset == SideLength - 1)
                {
                    AntiDiagonalSum += CurrentValue;
                }
            }
        }

        for (int Index = 0; Index < SideLength; Index++)
        {
            UniqueSums.Add(RowSums[Index]);
            UniqueSums.Add(ColumnSums[Index]);
        }

        UniqueSums.Add(MainDiagonalSum);
        UniqueSums.Add(AntiDiagonalSum);

        return UniqueSums.Count == 1;
    }
}