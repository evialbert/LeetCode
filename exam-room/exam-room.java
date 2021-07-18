class ExamRoom {

    int n;
	List<Integer> list;

	public ExamRoom(int N) {
		n = N;
		list = new ArrayList<>();
	}

	public int seat() {

		if (list.size() == 0) {
			list.add(0);
			return 0;
		}

		Integer prev = null;
		int maxDist = list.get(0);
		int seat = 0;

		for (int i = 0; i < list.size(); i++) {
			int curr = list.get(i);

			if (prev != null) {

				int d = (int) Math.floor((curr - prev) / 2);
				if (d > maxDist) {
					maxDist = d;
					seat = prev + d;
				}
			}

			prev = curr;
		}

		if (((n - 1) - list.get(list.size() - 1)) > maxDist) {
			seat = n - 1;
		}
		int j = 0;
		while (j < list.size() && list.get(j) < seat) {
			j++;
		}
		list.add(j, seat);
		return seat;
	}

	public void leave(int p) {
		int j = 0;
		while (j < list.size() && list.get(j) != p) {
			j++;
		}
		list.remove(j);
	}
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */