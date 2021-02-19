class Solution {
    public List<Integer> getRow(int rowIndex) {
      ArrayList<Integer> result = new ArrayList<Integer>();
 
	if (rowIndex < 0)
		return result;
 
	result.add(1);
	for (int i = 1; i <= rowIndex; i++) {
		for (int j = result.size() - 2; j >= 0; j--) {
			result.set(j + 1, result.get(j) + result.get(j + 1));
		}
		result.add(1);
	}
	return result;
  
    }
}