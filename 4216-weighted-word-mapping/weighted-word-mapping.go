func mapWordWeights(words []string, weights []int) string {
    var ans string 
    for _, w := range words {
        wgh := 0
        for _, r := range w {
            wgh += weights[r-'a']
        }
        ans += string('z' - wgh%26)
    }
    return ans
}