class Solution {
   public List<Integer> pancakeSort(int[] arr) {

		List<Integer> res = new ArrayList<>();

		int last = arr.length - 1;
		int lastnum = arr.length;

		int flipIndex = findLast(lastnum, arr);

		
		while (last > 0) {

			if (arr[0] == lastnum) {
				flip(arr, last);
				res.add(last+1);
				last--;
				lastnum--;
				flipIndex = findLast(lastnum, arr);
				
			} else {
				res.add(flipIndex + 1);
				flip(arr, flipIndex);
			}

		}

		return res;

	}

	int findLast(int lastNum, int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == lastNum)
				return i;
		}

		return 0;
	}

	void flip(int[] arr, int index) {
		int i = 0;
		int j = index;

		while (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;

		}

	}

}