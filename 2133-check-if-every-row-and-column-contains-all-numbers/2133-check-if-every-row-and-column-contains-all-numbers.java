class Solution {
   public boolean checkValid(int[][] matrix) {
			int rowsLength = matrix.length;
			int colsLength = matrix[0].length;
			HashSet<String> elements = new HashSet<>();
			for(int i=0;i<rowsLength;i++){
				for(int j=0;j<colsLength;j++){
					if(!elements.add("Row"+i+"ele"+matrix[i][j]) || !elements.add("Col"+j+"ele"+matrix[i][j]))
						return false;
				}
			}
			return true;
    }
}