func validSequence(word1 string, word2 string) []int {
	find := func(w1, w2 string, i, j int, res []int) bool {
		for i < len(w1) && j < len(w2) {
			if w1[i] == w2[j] {
				res[j] = i
				j++
				i++
			} else {
				i++
			}
		}
		return j == len(w2)
	}

	i, j := 0, 0
	res := make([]int, len(word2))
	for index := range res {
		res[index] = -1
	}

	for i < len(word1) && j < len(word2) && word1[i] == word2[j] {
		res[j] = i
		i++
		j++
	}

	for i < len(word1) && j < len(word2) {
		if find(word1, word2, i+1, j+1, res) {
			res[j] = i
			return res
		}
		for i < len(word1) && j < len(word2) {
			if word1[i] == word2[j] {
				for i < len(word1) && j < len(word2) && word1[i] == word2[j] {
					res[j] = i
					i++
					j++
				}
				break
			} else {
				i++
			}
		}
	}

	if j < len(word2) {
		return []int{}
	}

	return res
}