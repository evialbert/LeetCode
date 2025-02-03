class Solution {
    fun maxFreeTime(eventTime: Int, startTime: IntArray, endTime: IntArray): Int {
        var start = 0
        val freeSpacesList = mutableListOf<Pair<Int, Int>>()
        val freeSpaces = TreeSet<Pair<Int, Int>> { p1, p2 ->
            if (p1.first == p2.first) p1.second compareTo p2.second else p2.first compareTo p1.first
        }
        for (i in 0..startTime.size) {
            val bound = if (i == startTime.size) eventTime else startTime[i]
            val space = (bound - start) to start
            freeSpacesList += space
            freeSpaces += space
            if (i != startTime.size) {
                start = endTime[i]
            }
        }

        var ans = 0
        for (i in 0..startTime.lastIndex) {
            val left = freeSpacesList[i]
            val right = freeSpacesList[i + 1]
            freeSpaces.remove(left)
            freeSpaces.remove(right)
            val intervalLen = endTime[i] - startTime[i]
            val candidate = freeSpaces.floor(intervalLen to Int.MAX_VALUE)
            ans = max(
                ans, left.first + right.first +
                        (if (candidate != null && candidate.first >= intervalLen) intervalLen else 0)
            )
            freeSpaces += left
            freeSpaces += right
        }

        return ans
    }
}