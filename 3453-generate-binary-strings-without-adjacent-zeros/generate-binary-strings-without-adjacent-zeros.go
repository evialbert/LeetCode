func validStrings(n int) []string {
	result := []string{}
	Add01("0", &result, n)
	Add01("1", &result, n)
    return result
}

func Add01(s string, result *[]string, n int) {
	if len(s) == n {
		*result = append(*result, s)
		return
	}
	if s[len(s)-1] == '0' {
		Add01(s+"1", result, n)
	} else {
	Add01(s+"0", result, n)
	Add01(s+"1", result, n)
    }
    return
}