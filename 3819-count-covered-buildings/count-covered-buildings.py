class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        rows_map = {}
        cols_map = {}
        
        for row, col in buildings:
            if row not in rows_map:
                rows_map[row] = []
            rows_map[row].append(col)
            
            if col not in cols_map:
                cols_map[col] = []
            cols_map[col].append(row)
        
        row_min_col = {}
        row_max_col = {}
        col_min_row = {}
        col_max_row = {}
        
        for row, cols in rows_map.items():
            row_min_col[row] = min(cols)
            row_max_col[row] = max(cols)
        
        for col, rows in cols_map.items():
            col_min_row[col] = min(rows)
            col_max_row[col] = max(rows)
        
        covered_buildings = 0
        
        for row, col in buildings:
            if (row_min_col[row] < col and row_max_col[row] > col and
                col_min_row[col] < row and col_max_row[col] > row):
                covered_buildings += 1
        
        return covered_buildings