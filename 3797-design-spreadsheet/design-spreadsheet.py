class Spreadsheet:

    def __init__(self, rows: int):
        self.spreadSheet = defaultdict(int)
   
    def setCell(self, cell: str, value: int) -> None:
        self.spreadSheet[cell] = value
    
    def resetCell(self, cell: str) -> None:
        self.spreadSheet[cell] = 0
    
    def getValue(self, formula: str) -> int:
        if not formula.startswith('='):
            raise ValueError("Invalid Formula Type")

        expr = formula[1:]  # Remove '='
        parts = expr.split('+')

        if len(parts) != 2:
            raise ValueError("Only single '+' operator is supported.")

        def evalOperand(op):
            if op.isdigit():
                return int(op)
            return self.spreadSheet.get(op, 0)

        return evalOperand(parts[0]) + evalOperand(parts[1])

        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)