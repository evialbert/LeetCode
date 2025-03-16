class Spreadsheet {
    private int[][] dp;

    public Spreadsheet(int rows) {
        dp = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;
        dp[row][col] = value;
    }

    public void resetCell(String cell) {
        setCell(cell, 0);
    }

    public int getValue(String formula) {
        
        String[] parts = formula.substring(1).split("\\+");
        int sum = 0;
        
        for (String part : parts) {
            if (Character.isDigit(part.charAt(0))) {
                sum += Integer.parseInt(part);
            } else {
                int col = part.charAt(0) - 'A';
                int row = Integer.parseInt(part.substring(1)) - 1;
                sum += dp[row][col];
            }
        }
        
        return sum;
    }
}