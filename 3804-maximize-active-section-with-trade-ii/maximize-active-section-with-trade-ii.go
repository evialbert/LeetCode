
// Sparse Table
func maxActiveSectionsAfterTrade(s string, queries [][]int) []int {
	sparseTable := [][]int{{int(s[0] - '0'), 0, 0}}
	active := 0
	if s[0] == '1' {
		active++
	}
	for i := 1; i < len(s); i++ {
		if s[i] == '1' {
			active++
		}
		if s[i] == s[i-1] {
			sparseTable[len(sparseTable)-1][2]++
		} else {
			sparseTable = append(sparseTable, []int{int(s[i] - '0'), i, i})
		}
	}
	sparseTableActive := [][]int{}
	for i := 1; i < len(sparseTable)-1; i++ {
		if sparseTable[i][0] == 1 {
			sparseTableActive = append(sparseTableActive, []int{sparseTable[i][1], sparseTable[i][2], sparseTable[i-1][1], sparseTable[i+1][2]})
		}
	}
	rightOver := make([]int, len(sparseTableActive))
	if len(sparseTableActive) > 0 {
		rightOver[len(sparseTableActive)-1] = len(sparseTableActive) - 1
	}
	//
	monotonicStack := []int{len(sparseTableActive) - 1}
	for i := len(sparseTableActive) - 2; i >= 0; i-- {
		last := monotonicStack[len(monotonicStack)-1]
		ud := sparseTableActive[i][3] - sparseTableActive[i][2] - sparseTableActive[i][1] + sparseTableActive[i][0]
		lU := sparseTableActive[last][3] - sparseTableActive[last][2] - sparseTableActive[last][1] + sparseTableActive[last][0]
		for len(monotonicStack) > 0 && lU <= ud {
			monotonicStack = monotonicStack[:len(monotonicStack)-1]
			if len(monotonicStack) > 0 {
				last = monotonicStack[len(monotonicStack)-1]
				lU = sparseTableActive[last][3] - sparseTableActive[last][2] - sparseTableActive[last][1] + sparseTableActive[last][0]
			}
		}
		if len(monotonicStack) > 0 {
			rightOver[i] = last
		} else {
			rightOver[i] = i
		}
		monotonicStack = append(monotonicStack, i)
	}
	rs := make([]int, len(queries))
	for q := range queries {
		rs[q] = active
		am := 0
		idx, _ := sort.Find(len(sparseTableActive), func(i int) int {
			return queries[q][0] + 1 - sparseTableActive[i][0]
		})
		if idx >= 0 {
			for sIndex := idx; sIndex < len(sparseTableActive); sIndex++ {
				if sparseTableActive[sIndex][0] <= queries[q][0] {
					continue
				}
				if sparseTableActive[sIndex][1] >= queries[q][1] {
					break
				}
				//get better index from rightOver
				nextIDx := rightOver[sIndex]
				for sparseTableActive[nextIDx][2] >= queries[q][0] && sparseTableActive[nextIDx][3] <= queries[q][1] && nextIDx != sIndex {
					sIndex = nextIDx
					nextIDx = rightOver[sIndex]
				}
				ami := min(queries[q][1], sparseTableActive[sIndex][3]) - max(queries[q][0], sparseTableActive[sIndex][2]) - sparseTableActive[sIndex][1] + sparseTableActive[sIndex][0]
				am = max(am, ami)
				if nextIDx == sIndex && ami == sparseTableActive[sIndex][3]-sparseTableActive[sIndex][2]+sparseTableActive[sIndex][0]-sparseTableActive[sIndex][1] {
					break
				}
			}
		}
		rs[q] += am
	}

	return rs
}