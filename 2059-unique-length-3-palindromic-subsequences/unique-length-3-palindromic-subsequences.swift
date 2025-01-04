class Solution {
    func countPalindromicSubsequence(_ s: String) -> Int {
        let s = Array(s)

        var first: [Character: Int] = [:]
        var last: [Character: Int] = [:]
        for (i, char) in s.enumerated() {
            first[char] = first[char] ?? i
            last[char] = i
        }

        var answers: Int = 0
        for (i, left) in first {
            if let right = last[i], right != left {
                let mids = Set(s[(left + 1)..<right])
                answers += mids.count
            }
        }

        return answers
    }
}