class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        def countSolutions(total: int) -> int:
            if total < 0:
                return 0
            return (total + 2) * (total + 1) // 2

        m = limit + 1

        totalUnbounded = countSolutions(n)
        boundSubtractOne = 3 * countSolutions(n - m)
        boundAddTwo = 3 * countSolutions(n - 2 * m)
        boundSubtractThree = countSolutions(n - 3 * m)

        return (
            totalUnbounded
            - boundSubtractOne
            + boundAddTwo
            - boundSubtractThree
        )        